/* Simple Travelling Salesman Problem heuristics.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_vector_double.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include "../utils/utils.h"
#include "../datastructures/datastructures.h"

int *tsp_bs(gsl_vector **, int); /* brute-force search */
int *tsp_nn(gsl_vector **, int); /* nearest-neighbor */
int *tsp_cp(gsl_vector **, int); /* closest-pair */
double pathlen(gsl_vector **, int *, int); /* path length of a permutation. */

double pathlen(gsl_vector **data, int *path, int n){
  /* Compute the length of the path defined by the vectors
   * in `data`, traversed in order given in `path`,
   * and closing the loop by traversing path[n-1] -- path[0]
   * at the end.
   */
  int i;
  double total = 0.;
  for (i = 0; i < n-1; i++)
    total += vector_dist(data[path[i]], data[path[i+1]]);
  if (n > 0)
    total += vector_dist(data[path[n-1]], data[path[0]]);
  return total;
}


int *tsp_nn(gsl_vector **data, int n)
{
  /* Solve the TSP using the nearest-neighbor heuristic. */
  if (n == 0)
    return NULL;
  int i, j, best_id;
  int usedup = 0; /* Flag already-used elements. */
  gsl_vector *current = data[0];
  double cur_dist;
  double best_dist;
  int *nn_path = (int *) calloc(n, sizeof(int));
  
  nn_path[0] = 0;
  usedup |= 1;
  for (i = 1; i < n; i++){
    best_dist = 0;
    for (j = 1; j < n; j++){
      if (!(usedup & (2 << (j-1)))){
    	cur_dist = vector_dist(current, data[j]);
    	if (cur_dist < best_dist || best_dist == 0){
    	  best_dist = cur_dist;
	  best_id = j;
    	}
      }
    }
    current = data[best_id];
    nn_path[i] = best_id;
    usedup |= (2 << (best_id-1));
  }
  
  return nn_path;
}


int *tsp_cp(gsl_vector **data, int n)
{
  /* Solve the TSP using the closest pair heuristic. */
  int i, j, ch1_id, ch2_id, best_ch1, best_ch2;
  int match_flag;
  double dist, best_dist;
  dlist_node *node;
  int *best_path = (int *) calloc(n, sizeof(int));

  /* Create an array where each element corresponds to a chain. */
  dlist **chains = (dlist **) calloc(n, sizeof(dlist *));
  for (i = 0; i < n; i++){
    chains[i] = dlist_new(data[i]);
  }

  /* Merge the chains according to the heuristic. */
  for (i = 0; i < n-1; i++){
    /* Find the smallest-distance chain ends pair. */
    best_dist = 0.;
    for (ch1_id = 0; ch1_id < n; ch1_id++){
      if (chains[ch1_id] == NULL){
	continue;
      }
      for (ch2_id = 0; ch2_id < n; ch2_id++){
	if (chains[ch2_id] == NULL || ch1_id == ch2_id){
	  continue;
	}
	dist = vector_dist(chains[ch1_id]->head->item,
			   chains[ch2_id]->head->item);
	if (dist < best_dist || best_dist == 0){
	  /* Heads match. */
	  best_dist = dist;
	  best_ch1 = ch1_id;
	  best_ch2 = ch2_id;
	  match_flag = 0;
	}

	dist = vector_dist(chains[ch1_id]->head->item,
			   chains[ch2_id]->tail->item);
	if (dist < best_dist || best_dist == 0){
	  /* Head1 matches tail2. */
	  best_dist = dist;
	  best_ch1 = ch1_id;
	  best_ch2 = ch2_id;
	  match_flag = 1;
	}
	  
	dist = vector_dist(chains[ch1_id]->tail->item,
			   chains[ch2_id]->head->item);
	if (dist < best_dist || best_dist == 0){
	  /* Tail1 matches head2. */
	  best_dist = dist;
	  best_ch1 = ch1_id;
	  best_ch2 = ch2_id;
	  match_flag = 2;
	}
	  
	dist = vector_dist(chains[ch1_id]->tail->item,
			   chains[ch2_id]->head->item);
	if (dist < best_dist || best_dist == 0){
	  /* Tail1 matches tail2. */
	  best_dist = dist;
	  best_ch1 = ch1_id;
	  best_ch2 = ch2_id;
	  match_flag = 3;
	}
      }
    }
    printf("Iter %d, best match (%d, %d) %f\n",
	   i, best_ch1, best_ch2, best_dist);

    /* Merge the smallest-distance chain ends. */
    if (match_flag == 0){
      /* Heads match: push ch2 to the front of ch1 in reverse-order. */
      while(chains[best_ch2]->head){
	dlist_insert(chains[best_ch1], 
		     chains[best_ch2]->head->item);
	dlist_delete(chains[best_ch2], chains[best_ch2]->head);
      }
    }
    else if (match_flag == 1){
      /* Head1 to tail2 match: push ch2 to the front of ch1 in-order. */
      while(chains[best_ch2]->tail){
	dlist_insert(chains[best_ch1], 
		     chains[best_ch2]->tail->item);
	dlist_delete(chains[best_ch2], chains[best_ch2]->tail);
      }
    }
    else if (match_flag == 2){
      /* Head2 to tail1 match: push ch2 to the end of ch1 in-order. */
      while(chains[best_ch2]->head){
	dlist_insert_tail(chains[best_ch1], 
			  chains[best_ch2]->head->item);
	dlist_delete(chains[best_ch2], chains[best_ch2]->head);
      }
    }
    else if (match_flag == 3){
      /* Tails match: push ch2 to the end of ch1 in reverse-order. */
      while(chains[best_ch2]->tail){
	dlist_insert_tail(chains[best_ch1], 
			  chains[best_ch2]->tail->item);
	dlist_delete(chains[best_ch2], chains[best_ch2]->tail);
      }
    }
    chains[best_ch2] = NULL;
  }

  /* All the chains except for one should be null. The non-null
     chain contains the best (heuristic) path. */
  for (i = 0; i < n; i++)
    if (chains[i])
      node = chains[i]->head;

  for(i = 0; node; i++){
    for (j = 0; j < n; j++)
      if (data[j] == node->item)
	best_path[i] = j;
    node = node->next;
  } 
  return best_path;
}
       


int *tsp_bs(gsl_vector **data, int n)
{
  /* Find the shortest loop between `n` points. stored in `data`. */
  if (n == 0)
    return NULL;
  double best_dist = 0;
  double cur_dist = 0;
  int i_perm, i_iter;
  int *cur_path;
  int *best_path = calloc(n, sizeof(int));
  
  int **perm = permutations(n);
  for (i_iter = 0; i_iter < factorial(n); i_iter++){
    /* Retrieve the permutation into an array. */
    cur_path = perm[i_iter];

    /* Compute the path length corresponding to this permutation. */
    printf("Iter %d, permutation ", i_iter);
    print_intarray(cur_path, n);
    cur_dist = pathlen(data, cur_path, n);
    printf(" dist %.10f.\n", cur_dist);

    /* Save best pathlen to-date. */
    if (best_dist > cur_dist || best_dist == 0){
      best_dist = cur_dist;
      for (i_perm = 0; i_perm < n; i_perm++)
	best_path[i_perm] = cur_path[i_perm];
    }
  }
  printf("\n");
  free(cur_path);
  free(perm);
  return best_path;
}


int main(){
  char *fname;
  int npoints;
  int *bestpath;
  gsl_vector **vecs;

  /* Load data into a vector array. */
  fname = "tsp.dat";
  npoints = get_nlines(fname);
  vecs = load_vectors_from_file("tsp.dat", npoints);

  /* Compute the best path using the brute-force method. */
  bestpath = tsp_bs(vecs, npoints);
  printf("Best path (brute-force) len = %f, for path ",
	 pathlen(vecs, bestpath, npoints));
  print_intarray(bestpath, npoints);
  printf("\n");

  /* Compute the best path using the nearest-neighbor heuristic. */
  bestpath = tsp_nn(vecs, npoints);
  printf("Best path (nearest-neighbor) len = %f, for path ",
	 pathlen(vecs, bestpath, npoints));
  print_intarray(bestpath, npoints);
  printf("\n");

  /* Compute the best path using the closest-pairs heuristic. */
  bestpath = tsp_cp(vecs, npoints);
  printf("Best path (closest-pair) len = %f, for path ",
	 pathlen(vecs, bestpath, npoints));
  print_intarray(bestpath, npoints);
  printf("\n");

  return 0;
}
