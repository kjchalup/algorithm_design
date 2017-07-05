#include <stdio.h>
#include <stdlib.h>

int get_clen(int n){
  int counter = 1;
  while (n != 1){
    counter += 1;
    if (n % 2)
      n = 3 * n + 1;
    else
      n = n / 2;
  }
  return counter;
}

int main(){
  char *line = NULL;
  int a, b, x, best, cur, switched;
  size_t linelen;

  while (getline(&line, &linelen, stdin) > 1){
    sscanf(line, "%d %d", &a, &b);
    best = 0;

    if (a <= b){
      switched = 0;
    } 
    else {
      switched = 1;
      x = a; a = b; b = x;
    }
    
    for (x = a; x <= b; x++){
      cur = get_clen(x);
      if (cur > best)
	best = cur;
    }
    if (switched){
      printf("%d %d %d\n", b, a, best);
    }
    else{
      printf("%d %d %d\n", a, b, best);
    }
  }
  return 0;
}
