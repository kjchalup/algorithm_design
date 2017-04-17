#include <stdio.h>
#include <string.h>
#include "../algorithms/algorithms.h"

#define MAX_ROWS 50
#define MAX_COLS 50

char *suffix_array[MAX_ROWS * MAX_COLS * 8]; // data read-in

int main(void){
  int n_cases, m, n, k;
  int case_id, n_suf, row_id, col_id;
  char *line[1];
  size_t len, dummy;

  scanf("%d", &n_cases);
  
  for (case_id = 0; case_id < n_cases; case_id++){
    n_suf = 0;
    scanf("%d", &m);
    scanf("%d", &n);
    getchar(); // remove newline
    
    // Prepare a suffix array to read text into.
    for (row_id = 0; row_id < m; row_id++){
      line[0] = NULL;
      scanf("%s", suffix_array[n_suf]);
      len = getline(line, &dummy, stdin);
      line[0][len-1] = '\0'; // remove newline
      for (col_id = 0; col_id < n; col_id++){
	suffix_array[n_suf++] = (*line) + col_id;
      }
    }
    
    // Sort the array.
    quicksort((void **) suffix_array, n_suf, (comp_fn) strcmp);
    k=binary_search_arr((void **) suffix_array,
		      (void *) suffix_array[10], (comp_fn) strcmp, 0, n_suf);
    printf("%s\n", suffix_array[k]);
  }
  return 0;
}
