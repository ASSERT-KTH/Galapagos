#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int ctz(uint64_t in)
{
 int i, b, m = 0, r = 0;

 for (i = 0; i < 64; i++)
 {
  b = (in >> i) & 1;
  m |= b;
  r += (m^1) & (b^1);
 }

 return r;
}


int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        ctz(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
