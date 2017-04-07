#include <stdlib.h>
#include <stdio.h>

#define MAX_CANDIDATES 20
#define MAX_NAME 80
#define MAX_VOTERS 1000

char *cnames[MAX_CANDIDATES];
int votes[MAX_VOTERS][MAX_CANDIDATES];


void remove_id(int n_candidates, int n_votes, int remove){
  int i, j, k;
  for (i = 0; i < n_votes; i++){
    for (j = 0; j < n_candidates; j++){
      if (votes[i][j] == remove){
	votes[i][j] = 0;
	for (k = j + 1; k < n_candidates; k++){
	  votes[i][k-1] = votes[i][k];
	}
	votes[i][k] = 0;
	break;
      }
    }
  }
}
      
int winner(int n_candidates, int n_votes){
  int i, best_count, best_candidate;
  best_count = best_candidate = 0;
  int *ccounts = (int *) calloc(n_candidates, sizeof(int));
  for (i = 0; i < n_votes; i++){
    ccounts[votes[i][0]]++;
  }
  for (i = 0; i < n_candidates; i++){
    if (ccounts[i] > best_count){
      best_count = ccounts[i];
    }
  }
  free(ccounts);
  if (best_count >= n_candidates / 2.)
    return best_count;
  else
    /* Find the WORST vote count. */
    for (i = 0; i < n_candidates; i++){
      if (ccounts[i] < best_count){
	best_count = ccounts[i];
      }
    }
    return -best_count;
}

void reevaluate(int n_candidates, int n_votes, int worst){
  int i;

  int *ccounts = (int *) calloc(n_candidates, sizeof(int));
  for (i = 0; i < n_votes; i++){
    ccounts[votes[i][0]]++;
  }

  for (i = 0; i < n_votes; i++){
    if (ccounts[i] == worst){
      remove_id(n_candidates, n_votes, i);
    }
  }
}

int main(){
  int n_cases, case_id, n_candidates, voter_id, i, result;
  char *line;
  size_t size;
  scanf("%d", &n_cases);
  
  for(case_id = 0; case_id < n_cases; case_id++){
    scanf("%d", &n_candidates);

    /* Read in candidate names. */
    getline(&cnames[0], &size, stdin);
    for (i = 0; i < n_candidates; i++){
      getline(&cnames[i], &size, stdin);
    }

    /* Read in the votes. */
    voter_id = 0;
    while(getline(&line, &size, stdin) == 2 * n_candidates){
      for(i = 0; i < n_candidates; i++)
	scanf("%d", &votes[voter_id][i]);
      voter_id++;
    }

    /* Keep recounting votes until someone wins. */
    while((result = winner(n_candidates, voter_id-1)) < 0)
      reevaluate(n_candidates, voter_id-1, -result);
    
    /* And the winner is... */
    printf("%s", cnames[winner(n_candidates, voter_id-1)]);
  }
  return 0;
}
