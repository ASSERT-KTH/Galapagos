#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int int16_t_nonzero_mask (int16_t x)
{
  uint16_t u = x;
  uint32_t v = u;
  v = -v;
  v >>= 31;
  return -v;
}


int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        int16_t_nonzero_mask(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
