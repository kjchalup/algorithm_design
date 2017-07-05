/* Useful mathematical functions.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"


double min(double x, double y){
  return x < y ? x : y;
}
 
int factorial(int n){
  if (n < 0){
    crit_err("Can't take factorial of a negative number");
  }
  if (n == 1 || n == 0){
    return 1;
  }
  else{
    return n * factorial(n-1);
  }
}

int **permutations(int n){
  /* Return an array in which each element
   * is a permutation of the n integers 0, ..., n-1.
   */
  int i, j, k;
  int **perms_cur;
  int **perms_lower;
  int fac_cur = factorial(n);
  int fac_lower = factorial(n-1);

  /* Allocate the permutations array. */
  if((perms_cur = (int **) calloc(fac_cur, sizeof(int *))) == NULL)
    crit_err("Out of memory");
  for (i = 0; i < fac_cur; i++)
    if((perms_cur[i] = (int *) calloc(n, sizeof(int))) == NULL)
      crit_err("Out of memory");

  /* Fill out the permutations recursively. */
  if (n==1){
    perms_cur[0][0] = 0;
    return perms_cur;
  }
  else{
    perms_lower = permutations(n-1);
    for (i = 0; i < n; i++){
      for (j = 0; j < fac_lower; j++){
	for (k = 0; k < i; k++){
	  perms_cur[i*fac_lower + j][k] = perms_lower[j][k];
	}
	perms_cur[i * fac_lower + j][i] = n - 1;
	for (k = i + 1; k < n; k++){
	  perms_cur[i * fac_lower + j][k] = perms_lower[j][k-1];
	}
      }
    }
    return perms_cur;
  }
}

int test_mathutils(){
  int i, j;
  int N = 3;
  int **perms = permutations(N);

  /* Make sure factorial works as expected. */
  printf("Testing factorial:\n");
  factorial(3);
  for (i = 1; i < 7; i++)
    printf("factorial(%d) = %d\n", i, factorial(i));

  /* Make sure permutations work as expected. */
  printf("Testing permutations:\n");
  for (i = 0; i < factorial(N); i++){
    for (j = 0; j < N; j++){
      printf(" %d", perms[i][j]);
    }
    printf("\n");
  }
  return 0;
}
