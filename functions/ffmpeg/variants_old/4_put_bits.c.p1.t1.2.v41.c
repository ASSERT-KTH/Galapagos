Here's a program variant that attempts to optimize the loop by copying count of remaining bits and working with local variable directly:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    int remainingBits = n;
    int bitIndex = s->bit_index;
    while(remainingBits-- > 0){
        if (bitIndex == 8){
            bitIndex = *(s->buf) == 0xff ? 0 : bitIndex;
            *(s->buf + 1) = 0;
            ++s->buf;
        }
        *(s->buf) |= val << (7 - bitIndex);
        ++bitIndex;
    }
    s->bit_index = bitIndex;
}

In the program variant, I moved the bitwise operation within the while loop, which elongates the time each loop takes to run by a minimal amount. Also, moved s->bit_index to a local variable to avoid potential latency induced by possible complex computations while reading the class property at each while iteration. Increment s->buf only if bitIndex == 8 and update s->bit_index once at the end; this minimal change has kept the original idea but generally may affect runtime performance.
Please take into account that this changes perhaps lead to nearly negligible improvements in execution terms. It could even run the program a bit slower due to more bit-operations within each while iteration. Direct access to class properties could beneficial (or vice versa) in case your CPU instruction set architecture has dedicated solutions (ISA it is) for those functionality pieces and compiler can use it.