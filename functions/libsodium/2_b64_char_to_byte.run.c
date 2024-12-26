#include <stdint.h>
#include <stdio.h>
#include <time.h>

static unsigned int b64_char_to_byte(int c)
{
    const unsigned int x =
        ((((((unsigned int) (c) - (unsigned int) ('A')) >> 8) & 0xFF) ^ 0xFF) & (((((unsigned int) ('Z') - (unsigned int) (c)) >> 8) & 0xFF) ^ 0xFF) & (c - 'A')) |
        ((((((unsigned int) (c) - (unsigned int) ('a')) >> 8) & 0xFF) ^ 0xFF) & (((((unsigned int) ('z') - (unsigned int) (c)) >> 8) & 0xFF) ^ 0xFF) & (c - ('a' - 26))) |
        ((((((unsigned int) (c) - (unsigned int) ('0')) >> 8) & 0xFF) ^ 0xFF) & (((((unsigned int) ('9') - (unsigned int) (c)) >> 8) & 0xFF) ^ 0xFF) & (c - ('0' - 52))) | (((((0U - ((unsigned int) (c) ^ (unsigned int) ('+'))) >> 8) & 0xFF) ^ 0xFF) & 62) |
        (((((0U - ((unsigned int) (c) ^ (unsigned int) ('/'))) >> 8) & 0xFF) ^ 0xFF) & 63);

    return x | (((((0U - ((unsigned int) (x) ^ (unsigned int) (0))) >> 8) & 0xFF) ^ 0xFF) & (((((0U - ((unsigned int) (c) ^ (unsigned int) ('A'))) >> 8) & 0xFF) ^ 0xFF) ^ 0xFF));
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        b64_char_to_byte(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
