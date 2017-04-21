#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STUDENT 1000

double spending[MAX_STUDENT];

int main(){
  int n_students, i;
  double mean, debt, loan, diff;

  while(scanf("%d", &n_students) != EOF && n_students != 0){
    for (i = 0; i < n_students; i++)
      scanf("%lf", &spending[i]);
    mean = debt = loan = 0.;
    for (i = 0; i < n_students; i++){
      mean += spending[i];
    }
    mean /= n_students;
    for (i = 0; i < n_students; i++){
      diff = spending[i] - mean;
      if (diff > 0)
	loan += ((int) (diff * 100)) / 100.;
      else
	debt += ((int) (-diff * 100)) / 100.;
    }
    printf("$%.2f\n", fmax(debt, loan));
    fflush(stdout);
  }
  return 0;
}
