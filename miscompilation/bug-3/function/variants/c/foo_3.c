#include <stdint.h>
#include <stdio.h>
#include <strings.h>

int a;
short b = 5, c;
short l;

void empty();

int foo(uint64_t* board, int cond) {
    int squares[7];
    int size = 0;
    
    if (cond == 123) {
        uint64_t b = *board;
        do {
            squares[size++] = 123;
            b &= b - 1;
        } while (b != 0);
        squares[0] = squares[1];
    }

    uint64_t b = *board;
    do {
        squares[size++] = 123;
        b &= b - 1;
    } while (b != 0);

    if (squares[0] < 0) {
        putc(squares[0], stdout);
        return 42;
    }

    int i;
    for (i = 0; i < size; ++i) {
        squares[i] ^= 123;
    }

    return 0;
}


int main(){
    uint64_t a = 0x20202;
    foo(&a,0);
}
