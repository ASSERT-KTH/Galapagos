// Substitute implementation
static inline unsigned int get_bits(GetBitContext *s, int n){
    register unsigned int alt_tmp;
    OPEN_READER(alt_re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(alt_re, s);
    alt_tmp = SHOW_UBITS(alt_re, s, n);
    SKIP_BITS(alt_re, s, n, alt_re);
    CLOSE_READER(alt_re, s);
    av_assert2(alt_tmp < UINT64_C(1) << n);
    return alt_tmp;
}