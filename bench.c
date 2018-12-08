#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int minSize = atoi(argv[1]);
  int maxSize = atoi(argv[2]);  

  struct timespec t_start, t_stop; // Used for bench timings
  srand(time(NULL)); // Used for random

  long wall_sec; 
  long wall_nsec;
  long wall_msec;


  for(int k = sample; k <= numBlocks; k += sample) {
    clock_gettime(CLOCK_MONOTONIC_COARSE, &t_start);

    // Allocate random size between minSize and maxSize and do nr numBlocks
    for(int i = 0; i < k; i++) {
      balloc((int)(minSize + ((rand() % 10000) / 10000.0) *(maxSize - minSize)) % maxSize);
    }
    
    clock_gettime(CLOCK_MONOTONIC_COARSE, &t_stop);

    wall_sec = t_stop.tv_sec - t_start.tv_sec;
    wall_nsec = t_stop.tv_nsec - t_start.tv_nsec;
    wall_msec = (wall_sec *1000) + (wall_nsec / 1000000);
    printf("%d %ld\n", k, wall_msec);

  }

  return 0;
}
