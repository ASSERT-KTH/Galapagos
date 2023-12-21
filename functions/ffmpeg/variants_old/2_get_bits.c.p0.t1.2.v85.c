static inline unsigned int get_bits_variant(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(re_variant, s);
    assert(n>0 && n<= 25);  
    UPDATE_CACHE(re_variant, s);
    temp = SHOW_UBITS(re_variant, s, n);
    SKIP_BITS(re_variant, s, n);
    CLOSE_READER(re_variant, s);
    assert(temp < (1U << n));
    return temp;
}