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

int *tsp_bs(gsl_vector **data, int n)
{
  /* Find the shortest loop between `n` points. stored in `data`. */
  if (n == 0)
    return NULL;
  double best_dist = 0;
  double cur_dist = 0;
  int i_perm, i_iter;
  int *cur_path = calloc(n, sizeof(int));
  int *best_path = calloc(n, sizeof(int));
  
  gsl_permutation *perm = gsl_permutation_calloc(n);
  for (i_iter = 0; gsl_permutation_next(perm) != GSL_FAILURE; i_iter++){
    /* Retrieve the permutation into an array. */
    for (i_perm = 0; i_perm < n; i_perm++){
      cur_path[i_perm] = gsl_permutation_get(perm, i_perm);
    }
    
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
  return 0;
}
