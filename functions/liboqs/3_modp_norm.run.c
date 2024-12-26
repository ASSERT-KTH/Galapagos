#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int32_t modp_norm(uint32_t x, uint32_t p) {
    return (int32_t)(x - (p & (((x - ((p + 1) >> 1)) >> 31) - 1)));
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        modp_norm(0,0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
