/* Data structures and routines common to all chapters.
 *
 * Krzysztof Chalupka, 2017.
 */

/*
 * Geometry headers.
 */
typedef struct vector {
  double *coords;
  int dim;
} vector;

vector *init_v(double *, int);
vector *addv(vector *, vector *);
vector *scalar_multv(vector *, double);
double dotv(vector *, vector *);

    
