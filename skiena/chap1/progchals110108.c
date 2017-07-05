#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_CANDIDATES 20
#define MAX_NAME 80
#define MAX_VOTERS 1000
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

char *cnames[MAX_CANDIDATES];
int votes[MAX_VOTERS][MAX_CANDIDATES];

int array_equal(int *ar1, int *ar2, int n){
  int i;
  for (i = 0; i < n; i++)
    if (ar1[i] != ar2[i])
      return 0;
  return 1;
}

void eliminate_losers(int *losers, int n_losers, 
		      int n_candidates, int n_voters){
  int i, j, k, l;
  for (i = 0; i < n_losers; i++){
    for (j = 0; j < n_voters; j++){
      for (k = 0; k < n_candidates; k++){
	if (votes[j][k] == losers[i]){
	  for (l = k + 1; l < n_candidates; l++){
	    votes[j][l - 1] = votes[j][l];
	  }
	  votes[j][(n_candidates)-1] = 0;
	}
      }
    }
    n_candidates--;
  }
}

void who_won(int **winners, int *n_winners,
	     int n_candidates, int n_voters){
  int *results = (int *) calloc(n_candidates, sizeof(int));
  int *losers = (int *) calloc(n_candidates, sizeof(int));
  int *eliminated = (int *) calloc(n_candidates, sizeof(int));
  int i, best, worst, n_losers;
  n_losers = 0;

  for(;;){
    /* Reset results. */
    *n_winners = n_losers = best = 0;
    worst = n_voters;
    for (i = 0; i < n_candidates; i++){
      (*winners)[i] = 0;
      losers[i] = 0;
      results[i] = 0;
    }

    /* Count votes. */
    for (i = 0; i < n_voters; i++){
      results[votes[i][0]]++;
    }
    
    /* Find winners and losers. */
    for (i = 0; i < n_candidates; i++){
      if (eliminated[i]) continue;
      best = max(results[i], best);
      worst = min(results[i], worst);
    }
    
    for (i = 0; i < n_candidates; i++){
      if (eliminated[i]) continue;
      if (results[i] == best){
	(*winners)[*n_winners] = i;
	*n_winners += 1;
      }
      if (results[i] == worst){
	losers[n_losers] = i;
	n_losers += 1;
	eliminated[i] = 1;
      }
    }

    /* Check if anyone won. */
    if (best >= n_voters / 2.){
      break;
    }

    /* Check if everyone tied. */
    if ((n_losers == *n_winners) &&
	array_equal(losers, *winners, *n_winners)){
      break;
    }

    /* No one won. Eliminate losers. */
    eliminate_losers(losers, n_losers, n_candidates, n_voters);
  }
}

int main(){
  int *winners;
  int n_cases, case_id, n_candidates, i, j, n_winners, n_voters;
  size_t size;
  char c;

  scanf("%d\n", &n_cases);
  for(case_id = 0; case_id < n_cases; case_id++){
    scanf("%d\n", &n_candidates);

    /* Read in candidate names. */
    for (i = 0; i < n_candidates; i++)
      getline(&cnames[i], &size, stdin);

    /* Read in the votes. */
    for (i = 0; i < MAX_VOTERS; i++){
      for (j = 0; j < n_candidates; j++)
	scanf("%d", &votes[i][j]);
      getchar();
      if ((c = getchar()) == '\n' || c == EOF)
	break;
      else
	ungetc(c, stdin);
    }
    n_voters = i + 1;
 
    /* Decrease all vote ids by 1 to match C numbering. */
    for (i = 0; i < n_voters; i++)
      for (j = 0; j < n_candidates; j++)
    	votes[i][j]--;
    
    /* See who won. */
    winners = (int *) calloc(n_candidates, sizeof(int));
    who_won(&winners, &n_winners, n_candidates, n_voters);
    for (i = 0; i < n_winners; i++)
      printf("%s", cnames[winners[i]]);
    if (case_id < n_cases - 1)
      printf("\n");
    fflush(stdout);
  }
  return 0;
}
