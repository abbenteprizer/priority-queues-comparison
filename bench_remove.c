#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

#include "llpq.h" // Change all fnct names so we can also use heap?
//#include "heappq.h" // include this later

#define SAMPLES 20

int main(int argc, char *argv[]) {
  int numOperations = atoi(argv[1]);
  int typeOfOperation = atoi(argv[2]);
  int seed = atoi(argv[3]);

  double *timestamps;
  timestamps =  (double *)  malloc(sizeof(double) * numOperations);
  srand(seed); // Assign the seed to the function rand()
  for(int i = 0; i < numOperations; i++) {
    timestamps[i] = (rand() % 1000000) / 1000000.;
  }

  // for(int i = 0; i < 10; i++) {
  //   printf("%f\n", timestamps[i]);
  // }

  struct timespec t_start, t_stop; // Used for bench timings
  // srand(time(NULL)); // Used for random (actual random)

  long wall_sec;
  long wall_nsec;
  long wall_msec;

  int sample = numOperations/SAMPLES;


  for(int k = sample; k <= numOperations; k += sample) {

    struct node *pq = newQueue(5, 0.3); // random priority insert

    for(int i = 0; i < k; i++) {
       insert(&pq, i, timestamps[i]); // third arg, should be t_stamp rand func
    }

    // printf("got here \n");

    clock_gettime(CLOCK_MONOTONIC_COARSE, &t_start);
    for(int i = 0; i < k; i++) {
      if(!isEmpty(&pq)){
       removePriorityMax(&pq);
     }
    }
    clock_gettime(CLOCK_MONOTONIC_COARSE, &t_stop);

    wall_sec = t_stop.tv_sec - t_start.tv_sec;
    wall_nsec = t_stop.tv_nsec - t_start.tv_nsec;
    wall_msec = (wall_sec *1000) + (wall_nsec / 1000000);
    // printf("%d %ld\n", k, wall_msec);
    printf("%ld\n", wall_msec);

  }

  return 0;
}
