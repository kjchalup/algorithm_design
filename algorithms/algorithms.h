#ifndef SEARCH_H
#define SEARCH_H
typedef int (*comp_fn)(void *, void *);
int linear_search_arr(void **, void *, comp_fn, int);
int binary_search_arr(void **, void *, comp_fn, int, int);
void quicksort(void **, int, const comp_fn);
#endif
