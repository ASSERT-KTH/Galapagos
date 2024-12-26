#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int b64_byte_to_char(unsigned int x)
{
    return (((((unsigned int) (x) - (unsigned int) (26)) >> 8) & 0xFF) & (x + 'A')) |
           ((((((unsigned int) (x) - (unsigned int) (26)) >> 8) & 0xFF) ^ 0xFF) & ((((unsigned int) (x) - (unsigned int) (52)) >> 8) & 0xFF) & (x + ('a' - 26))) |
           ((((((unsigned int) (x) - (unsigned int) (52)) >> 8) & 0xFF) ^ 0xFF) & ((((unsigned int) (x) - (unsigned int) (62)) >> 8) & 0xFF) & (x + ('0' - 52))) | (((((0U - ((unsigned int) (x) ^ (unsigned int) (62))) >> 8) & 0xFF) ^ 0xFF) & '+') |
           (((((0U - ((unsigned int) (x) ^ (unsigned int) (63))) >> 8) & 0xFF) ^ 0xFF) & '/');
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        b64_byte_to_char(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
