#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int64_t int_sin(int64_t a)
{
    int64_t a2, res = 0;
    int i;
    if (a < 0) a = 3294199 -a;
    a %= 2 * 3294199;

    if (a >= 3294199*3/2) a -= 2*3294199;
    if (a >= 3294199/2 ) a = 3294199 - a;


    a2 = (a*a)/((1<<20));
    for (i = 2; i < 11; i += 2) {
        res += a;
        a = -a*a2 / ((1<<20)*i*(i+1));
    }
    return (res + 8)>>4;
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        int_sin(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
