#include <stdint.h>
#include <stdio.h>
#include <time.h>

static unsigned int iec958_parity(unsigned int data)
{
	unsigned int parity;
	int bit;

	data >>= 4;
	parity = 0;
	for (bit = 4; bit <= 30; bit++) {
		if (data & 1)
			parity++;
		data >>= 1;
	}
	return (parity & 1);
}


int main(){

    const int iterations = 2000000;
    struct timespec start, end;
    double total_time = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start); // Start timestamp
    for (int i = 0; i < iterations; i++) {
        iec958_parity(0);

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Start timestamp

    total_time = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    //total_time = (end.tv_nsec - start.tv_nsec);
    printf("%.4f\n", total_time);
}
