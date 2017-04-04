/* Unsorted doubly-linked list implementation.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <stdlib.h>
#include <stdio.h>
#include "datastructures.h"

void _print_int(int *);
int _comp_int(int *, int *);

dlist_node *dlist_search(dlist *list, void *item, comp_fn comp){
  dlist_node *node = list->head;
  while(node){
    if(comp(node->item, item) == 0)
      return node;
    node = node->next;
  }
  return NULL;
}


void dlist_delete(dlist **list, dlist_node *node){
  if((*list)->head == node && (*list)->tail == node){
    (*list)->head = (*list)->tail = NULL;
  } 
  else if((*list)->head == node){
    (*list)->head = node->next;
    (*list)->head->prev = NULL;
  }
  else if((*list)->tail == node){
    (*list)->tail = node->prev;
    (*list)->tail->next = NULL;
  }
  else if(node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  if(node)
    free(node);
}
  

void dlist_insert(dlist **list, void *item){
  /* Insert at the head of the list. */
  dlist_node *newnode = (dlist_node *) malloc(sizeof(dlist_node));
  newnode->item = item;
  newnode->prev = NULL;
  newnode->next = (*list)->head;

  if ((*list)->head == NULL){
    (*list)->head = newnode;
    (*list)->tail = newnode;
  }
  else {
    (*list)->head->prev = newnode;
    (*list)->head = newnode;
  }
}


void dlist_traverse(dlist *list, void (*fun)(void *)){
  /* Map a function onto a list. */
  dlist_node *node = list->head;
  while(node){
    fun(node->item);
    node = node->next;
  }
}


void _print_int(int *item){
  printf("%d ", *item);
}

int _comp_int(int *x, int *y){
  return *x - *y;
}

int main(){
  int i;
  dlist_node *node;
  int entries[5] = {1, 4, -10, 2, 10};

  /* Create an empty list. */
  dlist *list = (dlist *) malloc(sizeof(dlist));
  list->head = NULL;
  list->tail = NULL;

  /* Fill it with numers. */
  for (i = 0; i < 5; i++)
    dlist_insert(&list, &entries[i]);
  
  /* Print out the list contents. */
  printf("List after inserting [1, 4, -10, 2, 10]:\n");
  dlist_traverse(list, (void (*)(void *)) _print_int);
  printf("\n");

  printf("List after searching for and deleting 1:\n");
  i = 1;
  node = dlist_search(list, &i, (comp_fn) _comp_int);
  dlist_delete(&list, node);
  dlist_traverse(list, (void (*)(void *)) _print_int);
  printf("\n");

  printf("List after searching for and deleting -10:\n");
  i = -10;
  node = dlist_search(list, &i, (comp_fn) _comp_int);
  dlist_delete(&list, node);
  dlist_traverse(list, (void (*)(void *)) _print_int);
  printf("\n");

  printf("List after searching for and deleting 10:\n");
  i = 10;
  node = dlist_search(list, &i, (comp_fn) _comp_int);
  dlist_delete(&list, node);
  dlist_traverse(list, (void (*)(void *)) _print_int);
  printf("\n");

  return 0;
}
