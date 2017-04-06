#include "../algorithms/search.h"

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
typedef struct dlist_node {
  void *item;
  struct dlist_node *prev;
  struct dlist_node *next;
} dlist_node;

typedef struct dlist {
  dlist_node *head;
  dlist_node *tail;
} dlist;

dlist *dlist_new(void *);
dlist_node *dlist_search(dlist *, void *, comp_fn);
void dlist_insert(dlist *, void *);
void dlist_insert_tail(dlist *, void *);
void dlist_delete(dlist *, dlist_node *);
dlist_node *dlist_successor(dlist *, dlist_node *);
dlist_node *dlist_predecessor(dlist *, dlist_node *);
void *dlist_minimum(dlist *, comp_fn);
void *dlist_maximum(dlist *, comp_fn);
void dlist_traverse(dlist *, void (*)(void *));
#endif
