#include <stdint.h>

__attribute__((noinline,optnone))
void print_failure(int* f, int z) {}

__attribute__((noinline))
int do_table(uint64_t* board, int cond) {
    int squares[7];
    int size = 0;

    if (cond==123) {
        uint64_t b = *board;
        do { squares[size++] = 123; b&=b-1; } while (b);
       squares[0] = squares[1];
    }

    uint64_t b = *board;
    do { squares[size++] = 123; b&=b-1; } while (b);
    
    if (squares[0] < 0) {
        print_failure(squares, squares[0]);
        return 42;
    }

    for (int i = 0; i < size; ++i) squares[i]^= 123;

    return 0;
}


__attribute__((optnone))
int main(int argc, char* argv[]) {
    uint64_t v = 0x20202;
    int cond = -12345;
    return do_table(&v, cond);
    //printf("didn't fail");
}
