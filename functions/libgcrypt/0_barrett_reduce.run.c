#include <stdint.h>
#include <stdio.h>
#include <time.h>

int16_t barrett_reduce(int16_t a) {
  int16_t t;
  const int16_t v = ((1<<26) + 3329/2)/3329;

  t = ((int32_t)v*a + (1<<25)) >> 26;
  t *= 3329;
  return a - t;
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        barrett_reduce(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
