#include <stdio.h>
#include <string.h>
#include "../algorithms/algorithms.h"

#define MAX_ROWS 50
#define MAX_COLS 50

char *suffix_array[MAX_ROWS * MAX_COLS * 8]; // data read-in
int comp_suffs(char *, char *);


int main(void){
  int n_cases, m, n, k;
  int case_id, n_suf, row_id, col_id, word_id;
  int x_coord;
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
	suffix_array[n_suf++] = line[0] + col_id;
      }
    }
    
    // Sort the array.
    quicksort((void **) suffix_array, n_suf, (comp_fn) strcmp);

    // Search for each word.
    scanf("%d", &k);
    getchar(); // remove newline
    for (word_id = 0; word_id < k; word_id++){
      line[0] = NULL;
      len = getline(line, &dummy, stdin);
      line[0][len-1] = '\0'; // remove newline
      printf("%d/%d, %s\n", word_id, k, line[0]);
      x_coord = binary_search_arr((void **) suffix_array, (void *) line[0],
      			    (comp_fn) comp_suffs, 0, n_suf);
      printf("%s: %d\n", line[0], x_coord);
    }
  }
  return 0;
}


int comp_suffs(char *suffix, char *findme)
{
  return strncmp(suffix, findme, strlen(findme));
}
