#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int int16_nonzero_mask(int16_t x) {
    uint16_t u = (uint16_t) x; /* 0, else 1...65535 */
    uint32_t v = u; /* 0, else 1...65535 */
    v = ~v + 1; /* 0, else 2^32-65535...2^32-1 */
    v >>= 31; /* 0, else 1 */
    return -(int) v; /* 0, else -1 */
}


int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        int16_nonzero_mask(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
