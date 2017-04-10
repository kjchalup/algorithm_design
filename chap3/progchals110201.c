#include <stdio.h>
#include <math.h>
#define abs(x) ((x) > 0 ? (x) : -(x))
#define MAX_NUMS 3000

int nums[MAX_NUMS];

int main(void){
  int prev, cur, i, j, diff, n, jolly;
  while (scanf("%d", &n) > 0){
    prev = cur =  0;
    jolly = 1;
    for (i = 0; i < n; i++){
      prev = cur;
      scanf("%d", &cur);
      if (i > 0){
	diff = abs(prev - cur);
	if (0 < diff && diff < MAX_NUMS)
	  nums[diff] = 1;
      }
    }
    for (j = 1; j < n; j++){
      if (!nums[j])
	jolly = 0;
      nums[j] = 0;
    }
    printf("%s\n", jolly? "Jolly" : "Not jolly");
  }
  return 0;
}
