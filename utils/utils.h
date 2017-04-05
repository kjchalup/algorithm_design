#include <gsl/gsl_vector_double.h>

#ifndef UTILS_H
#define UTILS_H

int get_nlines(char *);
void print_gsl_vector(gsl_vector *);
void print_intarray(int *, int);
gsl_vector *vector_sub(gsl_vector *, gsl_vector *);
double vector_dist(gsl_vector *, gsl_vector *);
gsl_vector **load_vectors_from_file(char *, int);

#endif
