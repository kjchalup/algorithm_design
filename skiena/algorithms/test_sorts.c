/* Tests for search algorithms.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <stdio.h>
#include "algorithms.h"

float test_quicksort();
int comp_int(int *, int *);

int main()
{
  float quick_success;
  
  /* Run the tests. */
  quick_success = test_quicksort();
  
  /* Print the score. */
  printf("Quicksort success rate: %.2f\n", quick_success);

  return 0;
}


int comp_int(int *i, int *j){
  /* Compare the integers pointed to. */
  return *i - *j;
}


float test_quicksort()
{
  int success = 0;
  int N = 10;
  /* Make a test array of pointers to int. */
  int *arr[N];
  int vals[] = {2, -10, 0, 100, 22, 3, -3, 11, 2, -11};
  int sorted[] = {-11, -10, -3, 0, 2, 2, 3, 11, 22, 100};
  int i;
  for (i = 0; i < N; i++){
    arr[i] = &vals[i];
  }

  quicksort((void **) arr, N, (comp_fn) &comp_int);
  for (i = 0; i < N; i++)
    if (*arr[i] == sorted[i])
      success++;

  return success / (float) N;
}
