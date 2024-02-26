#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static uint64_t Chi(uint64_t A[5][5], uint64_t i)
{
    uint64_t C[5];
    size_t y;

    for (y = 0; y < 5; y++) {
        C[0] = A[y][0] ^ (~A[y][1] & A[y][2]);
        C[1] = A[y][1] ^ (~A[y][2] & A[y][3]);
        C[2] = A[y][2] ^ (~A[y][3] & A[y][4]);
        C[3] = A[y][3] ^ (~A[y][4] & A[y][0]);
        C[4] = A[y][4] ^ (~A[y][0] & A[y][1]);

        A[y][0] = 5;
        //A[y][0] = C[0];
        A[y][1] = C[1];
        A[y][2] = C[2];
        A[y][3] = C[3];
        A[y][4] = C[4];
    }

    return C[i];
}

int main(){
    uint64_t A[5][5];
    printf("%ld\n", Chi(A, 10));
    return 0;
}
