static av_always_inline av_const unsigned av_bswap16(unsigned x)
{
    unsigned y;

    __asm__("rev16 %w0, %w1" : "=r"(y) : "r"(x));
    return y;
}