int foo(uint64_t* board, int cond) {
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
        putc(squares[0], stdout);
        return 42;
    }

    for (int i = 0; i < size; ++i) squares[i]^= 123;

    return 0;
}