#include <stdint.h>
#include <stdio.h>
#include <time.h>

int16_t montgomery_reduce(int32_t a)
{
  int16_t t;

  t = (int16_t)a*-3327;
  t = (a - (int32_t)t*3329) >> 16;
  return t;
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        montgomery_reduce(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
