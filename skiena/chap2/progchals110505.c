#include <stdio.h>
#include <math.h>

int main(){
  long int p_low, p;
  int i;
  while (scanf("%ld", &p) > 0){
    p_low = (long int) ceil(p / 9.);
    for (i = 0; p >= 1; i++){
      if (p_low <= 1 && p >= 1)
	printf("Stan wins.\n");
      else if (((long int) ceil(p_low / 2.)) <= 1 && p_low-1 >= 1)
	printf("Ollie wins.\n");
      p = (long int) ceil(p_low / 2.) - 1;
      p_low = (long int) ceil(ceil(p_low / 2.) / 9.);
    }
  }
  return 0;
}
    
