#include <stdint.h>
#include <stdio.h>
#include <time.h>

static unsigned int _booth_recode_w5(unsigned int in)
{
    unsigned int s, d;

    s = ~((in >> 5) - 1);
    d = (1 << 6) - in - 1;
    d = (d & s) | (in & ~s);
    d = (d >> 1) + (d & 1);

    return (d << 1) + (s & 1);
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        _booth_recode_w5(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
