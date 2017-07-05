/* Useful general-purpose functions.
 *
 * Krzysztof Chalupka, 2017.
 */

#include <stdio.h>
#include <gsl/gsl_blas.h>
#include "utils.h"

void crit_err(char *msg){
  fprintf(stderr, "%s, exiting.\n", msg);
  exit(1);
}

int get_nlines(char *fname){
  /* Check how many lines there are in a file. */
  int nlines = 0;
  FILE *f = fopen(fname, "r");
  while(!feof(f))
    if (fgetc(f) == '\n')
      nlines++;
  fclose(f);
  printf("%d lines read from %s.\n\n", nlines, fname);
  return nlines;
}

void print_intarray(int *arr, int n){
  int i;
  printf("[");
  for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("]");
}

void print_gsl_vector(gsl_vector *vec){
  int i;
  for (i = 0; i < vec->size; i++)
    printf("%.4f ", vec->data[i]);
}

gsl_vector *vector_sub(gsl_vector *v1, gsl_vector *v2){
  /* Create a new vector equal to v1 - v2. */
  gsl_vector *res = gsl_vector_calloc(v1->size);
  gsl_vector_add(res, v1);
  gsl_vector_sub(res, v2);
  return res;
}

double vector_dist(gsl_vector *v1, gsl_vector *v2){
  /* Compute the Euclidean distance between vectors. */
  double dist;
  gsl_vector *tmp =  vector_sub(v1, v2);
  dist = gsl_blas_dnrm2(tmp);
  free(tmp);
  return dist;
}

gsl_vector **load_vectors_from_file(char *fname, int nvecs)
{
  int vec_id;
  FILE *f;
  gsl_vector **vecs;
  double vals[2] = {0., 0.};
  
  /* Allocate the vector array. */
  vecs = (gsl_vector **) calloc(nvecs, sizeof(gsl_vector *));
      
  /* Load the vectors from a file into an array. */
  f = fopen(fname, "r");
  vec_id = 0;
  while(fscanf(f,"%lf %lf", &vals[0], &vals[1]) != EOF){
    vecs[vec_id] = gsl_vector_alloc(2);
    gsl_vector_set(vecs[vec_id], 0, vals[0]);
    gsl_vector_set(vecs[vec_id], 1, vals[1]);
    vec_id++;
  }

  /* Clean up. */
  fclose(f);
  printf("Data: \n");
  for (vec_id = 0; vec_id < nvecs; vec_id++)
    printf("[%f, %f]\n", 
	   vecs[vec_id]->data[0], 
	   vecs[vec_id]->data[1]);
  printf("\n");
  return vecs;
}
