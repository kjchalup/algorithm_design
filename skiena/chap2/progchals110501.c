#include <stdio.h>
#include <math.h>
#define MAX_POS 9

int main(){
  unsigned long int x, y;
  int dx, dy, pos, carry, ncrry;

  while (scanf("%lu %lu", &x, &y) && !(x == 0 && y == 0)){
    carry = ncrry = 0;
    for (pos = 0; pos < MAX_POS; pos++){
      dx = x % 10;
      dy = y % 10;
      x /= 10;
      y /= 10;
      if (dx + dy + carry >= 10){
	carry = 1;
	ncrry++;
      }
      else
	carry = 0;
    }
    if (ncrry == 0)
      printf("No carry operation.\n");
    else
      printf("%d carry operation%s.\n", ncrry, ncrry == 1 ? "" : "s");
  }
  return 0;
}
