#include <stdint.h>
#include <stdio.h>
#include <time.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps)
{




    int count;

    count = 16;
    count += ch * ((7+bps+7)/8);
    if (ch == 2) {

        count += (( 2*bps+1) * blocksize + 7) / 8;
    } else {
        count += ( ch*bps * blocksize + 7) / 8;
    }
    count += 2;

    return count;
}

int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        flac_get_max_frame_size(0,0,0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
