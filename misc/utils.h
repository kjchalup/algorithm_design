#include <gsl/gsl_vector_double.h>
int get_nlines(char *);
void print_gsl_vector(gsl_vector *);
gsl_vector *vector_sub(gsl_vector *, gsl_vector *);
gsl_vector **load_vectors_from_file(char *, int);