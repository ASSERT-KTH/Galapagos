#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int weight(int i, int blen, int offset)
{



    if (i < 2*offset)
        return offset == 1 ? ((i) ? 5 : 3) : (1 + (6*(i) + offset - 1) / (2*offset - 1));
    else if (i > blen-1 - 2*offset)
        return offset == 1 ? ((blen-1 - i) ? 5 : 3) : (1 + (6*(blen-1 - i) + offset - 1) / (2*offset - 1));
    return 8;
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        weight(0,0,0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
