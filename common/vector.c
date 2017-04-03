/* Simple routines for processing 2d points.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <stdlib.h>
#include "common.h"

vector *_coordwise(vector *, vector *, double,
		   double (*)(double, double, double));

vector *init_v(double coords[], int dim)
{
  /* Make a new vector. */
  vector *v = (vector *) malloc(sizeof(vector));
  v->dim = dim;
  v->coords = coords;
  return v;
}

vector *_coordwise(vector *v1, vector *v2,
		   double c, double (*fun)(double, double, double)){
  /* Create a new vector v, and apply function fun
     coordinate-wise to v1, v2, c, storing the result in v.
  */
  int i;
  vector *v = (vector *) malloc(sizeof(vector));
  v->dim = v1->dim;
  v->coords = (double *) calloc(v->dim, sizeof(double));
  for (i = 0; i < v->dim; i++)
    v->coords[i] = fun(v1->coords[i], v2->coords[i], c);
  return v;
}

double _add(double x, double y, double dummy){
  return x + y;
}

double _mult(double x, double y, double dummy){
  return x * y;
}

double _scale(double x, double dummy, double c){
  return c * x;
}

vector *addv(vector *v1, vector *v2)
{
  /* Given two points, create their sum. */
  return _coordwise(v1, v2, 0, _add);
}

vector *scalar_multv(vector *v, double c)
{
  /* Create the multiple of vector v by a scalar. */
  return _coordwise(v, v, c, _scale);
}

double dotv(vector *v1, vector *v2)
{
  /* Create the dot product of two vectors. */
  int i;
  double sum = 0.;
  vector *v = _coordwise(v1, v2, 0, _mult);
  for (i = 0; i < v->dim; i++){
    sum += v->coords[i];
  }
  return sum;
}
