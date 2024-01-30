static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    // Instead of using OPEN_READER macro directly, use the equivalent code
    unsigned int index = s->index;
    int limit = s->size_in_bits - index;

    av_assert2(n > 0 && n <= 25);

    // Instead of using UPDATE_CACHE macro directly, use the equivalent code
    uint64_t cache = 0;
    while(limit < 32){
        limit += 8, index -= 8;
        cache |= (uint64_t)s->buffer[index>>3] << limit;
    }

    tmp = (cache >> (32 - n)) & ((UINT64_C(1) << n) - 1);

    tmp = tmp & ((UINT64_C(1) << n) - 1);

    // Replace the LAST_SKIP_BITS macro by directly adding n to s->index
    s->index = s->index + n;

    // Instead of using CLOSE_READER macro, explicitly write the OPERANDS inside the macro.
    int needed_bits = s->index - index;
    if(needed_bits <= s->bits_left)
        s->bits_left -= needed_bits;

    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}