/* Tests for common code.
 *
 * Krzysztof Chalupka, 2017.
 */
#include <stdio.h>
#include "common.h"

double test_vector();

int main()
{
  double vector_success;
  
  /* Run the tests. */
  vector_success = test_vector();
  
  /* Print the score. */
  printf("Vector success rate: %.2f\n", vector_success);
  
  return 0;
}

double test_vector()
{
  double success = 0;
  double coords1[] = {.1, .2, .3};
  double coords2[] = {10., 11., 12.};
  vector *v1 = init_v(coords1, 3);
  vector *v2 = init_v(coords2, 3);

  vector *sum = addv(v1, v2);
  double dot = dotv(v1, v2);
  vector *sm = scalar_multv(v1, -1);
  double dist = distv(v1, v2);
  
  if (v1->coords[0] == .1 &&
      v1->coords[1] == .2 &&
      v1->coords[2] == .3){
    success += 1.;
    printf("1 ");
  }

  if (sum->coords[0] == 10.1 &&
      sum->coords[1] == 11.2 &&
      sum->coords[2] == 12.3){
    success += 1.;
    printf("2 ");
  }

  if (dot == (10 * .1 + 11 * .2 + 12 * .3)){
    success += 1.;
    printf("3 ");
  }
  
  if (sm->coords[0] == -.1 &&
      sm->coords[1] == -.2 &&
      sm->coords[2] == -.3){
    success += 1.;
    printf("4 ");
  }
  
  if (dist > 18.748 && dist < 18.75){
    success += 1.;
    printf("5 ");
  }

  printf("\n");
  return success / 5.;
}
  
    
