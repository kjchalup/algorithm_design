#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_vector_double.h>

#ifndef UTILS_H
#define UTILS_H
#define max
int get_nlines(char *);
void print_gsl_vector(gsl_vector *);
void print_intarray(int *, int);
gsl_vector *vector_sub(gsl_vector *, gsl_vector *);
double vector_dist(gsl_vector *, gsl_vector *);
gsl_vector **load_vectors_from_file(char *, int);
int **permutations(int);
int factorial(int);
double min(double, double);
void crit_err(char *);

#endif
