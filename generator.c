#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  srand(51252951);
  for(int i = 0; i< 10; i++) {
    printf("%f\t\n", (rand()%1000000) / 1000000.);
  }
}
