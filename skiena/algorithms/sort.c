#include <stdlib.h>
#include <stdio.h>
#include "algorithms.h"

void quick(void **, int, int, int, void **, const comp_fn);

void quicksort(void **arr, int n, const comp_fn f_comp){
  /* Sort an array of n items in n log(n) time. */
  void **copy = (void *) calloc(n, sizeof(void *));
  quick(arr, 0, n, 0, copy, f_comp);
  free(copy);
}

void quick(void **arr, int low, int high,
	   int pivot, void **copy, const comp_fn f_comp){
  int i, i_low, i_high, new_pivot;
  i_low = low;
  i_high = high - 1;

  // Sort to the left and right of pivot.
  for (i = low; i < high; i++){
    if (i == pivot) continue;
    if (f_comp(arr[i], arr[pivot]) <= 0)
      copy[i_low++] = arr[i];
    else
      copy[i_high--] = arr[i];
  }
  new_pivot = i_low;
  copy[new_pivot] = arr[pivot];
  
  // Copy over to the main array.
  for (i = low; i < high; i++)
    arr[i] = copy[i];
      
  // Continue recursively.
  if (low < new_pivot - 1)
    quick(arr, low, new_pivot, low, copy, f_comp);
  if (high > new_pivot + 2)
    quick(arr, new_pivot + 1, high, new_pivot + 1, copy, f_comp);
}
