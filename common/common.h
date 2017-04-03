/* Data structures and routines common to all chapters.
 *
 * Krzysztof Chalupka, 2017.
 */

/*
 * Vector headers.
 */
typedef struct vector {
  double *coords;
  int dim;
} vector;

vector *init_v(double *, int);
vector *addv(vector *, vector *);
vector *scalar_multv(vector *, double);
double dotv(vector *, vector *);
double distv(vector *, vector *);

/*
 * Functional programming headers.
 */
double reduce(double *, double (*)(double, double), int);
double reduce_add(double, double);

    
