/* Search algorithm implementations.
 *
 * Krzysztof Chalupka, 2017.
 */
#include "algorithms.h"

int linear_search_arr(void *arr[], void *findme, comp_fn comp, int n)
{
  /* Find element `findme` in array `arr` of length at most `n`.
     Return the index of the element or -1.
  */
  int i = 0;
  for (i = 0; i < n; i++){
    if(!comp(arr[i], findme)){
      return i;
    }
  }
  return -1;
}

int binary_search_arr(void *arr[], void *findme,
		      comp_fn comp, int left, int right)
{
  /* Find element `findme` in array `arr` of length at most `n`.
     Return the index of the element or -1.
     Assuming `arr` is sorted, use binary search.
  */
  if (left == right)
    return -1;

  int mid = left + (right - left) / 2;
  if (comp(arr[mid], findme) < 0){
    return binary_search_arr(arr, findme, comp, mid + 1, right);
  } 
  else if (comp(arr[mid], findme) > 0){
    return binary_search_arr(arr, findme, comp, left, mid);
  }
  else
    return mid;
}
