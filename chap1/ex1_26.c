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
#include "../misc/utils.h"

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
  gsl_vector *vdiff;
  double total = 0.;
  for (i = 0; i < n-1; i++){
    vdiff = vector_sub(*(data + path[i]), *(data + path[i+1]));
    total += gsl_blas_dnrm2(vdiff);
    free(vdiff);
  }
  vdiff = vector_sub(*(data + path[n-1]), *(data + path[0]));
  total += gsl_blas_dnrm2(vdiff);
  free(vdiff);
  return total;
}

int *tsp_nn(gsl_vector **data, int n)
{
  /* Solve the TSP using the nearest-neighbor heuristic. */
  

int *tsp_bs(gsl_vector **data, int n)
{
  /* Find the shortest loop between `n` points. stored in `data`. */
  double best_dist = 0;
  double cur_dist = 0;
  int i_perm, i_iter;
  int *cur_path = calloc(n, sizeof(int));
  int *best_path = calloc(n, sizeof(int));
  
  gsl_permutation *perm = gsl_permutation_calloc(n);
  for (i_iter = 0; gsl_permutation_next(perm) != GSL_FAILURE; i_iter++){
    printf("Iter %d, permutation [", i_iter);
    /* Retrieve the permutation into an array. */
    for (i_perm = 0; i_perm < n; i_perm++){
      cur_path[i_perm] = gsl_permutation_get(perm, i_perm);
      printf("%d ", cur_path[i_perm]);
    }
    printf("], ");
    
    /* Compute the path length corresponding to this permutation. */
    cur_dist = pathlen(data, cur_path, n);
    printf("dist %.10f.\n", cur_dist);

    /* Save best pathlen to-date. */
    if (best_dist == 0 || best_dist > cur_dist){
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

  /* Compute the best path using the brute-force heuristic. */
  bestpath = tsp_bs(vecs, npoints);
  return 0;
}
