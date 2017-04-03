/* Simple Travelling Salesman Problem heuristics. 
 *
 * Krzysztof Chalupka, 2017.
 */
#include <limits.h>
#include <stdio.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_vector_double.h>
#include <gsl/gsl_blas.h>

int *tsp_bs(gsl_vector *, int); /* brute-force search */
int *tsp_nn(gsl_vector *, int); /* nearest-neighbor */
int *tsp_cp(gsl_vector *, int); /* closest-pair */
double pathlen(gsl_vector *, int *, int); /* path length of a permutation. */

double pathlen(gsl_vector *data, int *path, int n){
  int i;
  double total = 0.;
  for (i = 0; i < n-1; i++){
    gsl_vector_sub((data + path[i]), (data + path[i+1]));
    total += gsl_blas_dnrm2(data + path[i]);
  }
  return total;
}

int *tsp_bs(gsl_vector *data, int n)
{
  /* Find the shortest loop between the points. */
  double best_dist = 0;
  double cur_dist = 0;
  int i;
  int *cur_path = calloc(n, sizeof(int));
  int *best_path = calloc(n, sizeof(int));
  
  gsl_permutation *perm = gsl_permutation_calloc(n);
  while (gsl_permutation_next(perm) != GSL_FAILURE){
    /* Retrieve the permutation into an array. */
    for (i = 0; i < n; i++)
      cur_path[i] = gsl_permutation_get(perm, i);
    
    /* Compute the path length corresponding to this permutation. */
    cur_dist = pathlen(data, cur_path, n);

    /* Save best pathlen to-date. */
    if (best_dist == 0 || best_dist > cur_dist){
      best_dist = cur_dist;
      for (i = 0; i < n; i++)
	best_path[i] = cur_path[i];
    }
  }
  return best_path;
}

int main(){
gsl_vector *v1 = gsl_vector_alloc(3);
{
FILE *f = fopen("tsp.dat", "r");
gsl_vector_fscanf(f, v1);
fclose(f);
}
printf("%f", gsl_vector_get(v1, 0));
return 0;
}
