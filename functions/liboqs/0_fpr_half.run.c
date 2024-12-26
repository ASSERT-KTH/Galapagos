#include <stdint.h>
#include <stdio.h>
#include <time.h>

static uint64_t fpr_half(uint64_t x) {
    /*
     * To divide a value by 2, we just have to subtract 1 from its
     * exponent, but we have to take care of zero.
     */
    uint32_t t;

    x -= (uint64_t)1 << 52;
    t = (((uint32_t)(x >> 52) & 0x7FF) + 1) >> 11;
    x &= (uint64_t)t - 1;
    return x;
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        fpr_half(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
