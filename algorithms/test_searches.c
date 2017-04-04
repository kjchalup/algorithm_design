/* Tests for search algorithms.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <stdio.h>
#include "search.c"

float test_linear_search();
float test_binary_search();
int comp_int(int *, int *);
int comp_char(char *, char *);

int main()
{
  float linear_success;
  float binary_success;
  
  /* Run the tests. */
  linear_success = test_linear_search();
  binary_success = test_binary_search();
  
  /* Print the score. */
  printf("Linear search success rate: %.2f\n", linear_success);
  printf("Binary search success rate: %.2f\n", binary_success);

  return 0;
}

float test_linear_search()
{
  int success = 0;
  int val = 100;

  /* Make a test array of pointers to int. */
  int *arr[4];
  int vals[4] = {4, 2, 5, 0};
  int i;
  for (i = 0; i < 4; i++){
    arr[i] = &vals[i];
  }

  success += (linear_search_arr((void **) arr, &vals[0],\
  				(comp_fn) &comp_int, 4) == 0);
  success += (linear_search_arr((void **) arr, &vals[2],\
  				(comp_fn) &comp_int, 4) == 2);
  success += (linear_search_arr((void **) arr, &vals[3],\
  				(comp_fn) &comp_int, 4) == 3);
  success += (linear_search_arr((void **) arr, &val,\
  				(comp_fn) &comp_int, 4) == -1);
  return success / 4.;
}

float test_binary_search()
{
  int success = 0;
  int val = 100;

  /* Make a test array of pointers to int. */
  int *arr[4];
  int vals[4] = {-10, -1, 0, 233};
  int i;
  for (i = 0; i < 4; i++){
    arr[i] = &vals[i];
  }

  success += (binary_search_arr((void **) arr, &vals[0],\
  				(comp_fn) &comp_int, 0, 4) == 0);
  success += (binary_search_arr((void **) arr, &vals[2],\
  				(comp_fn) &comp_int, 0, 4) == 2);
  success += (binary_search_arr((void **) arr, &vals[3],\
  				(comp_fn) &comp_int, 0, 4) == 3);
  success += (binary_search_arr((void **) arr, &val,\
  				(comp_fn) &comp_int, 0, 4) == -1);
  return success / 4.;
}

int comp_int(int *i, int *j){
  /* Compare the integers pointed to. */
  return *i - *j;
}
