/* Functional programming routines.
 *
 * Krzysztof Chalupka, 2017.
 */

double reduce_add(double x, double y)
{
  return x + y;
}

double reduce(double *vals, double (*fun)(double, double), int n)
{
  /* Standard functional programming reduction, starting from 
   *  0 on the left.
   */
  int i;
  double res = 0.;
  for (i = 0; i < n; i++)
    res = fun(res, vals[i]);
  return res;
}
