#include <stdio.h>
#include <math.h>

int main(void){
  unsigned long int d, sqr;
  while (scanf("%lu", &d) > 0 && d != 0){
    sqr = (unsigned long int) sqrt((double) d);
    printf("%s\n", sqr * sqr == d ? "yes" : "no");
  }
  return 0;
}
