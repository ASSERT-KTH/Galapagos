static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int slightly_changed_tmp;
    OPEN_READER(slightly_changed_re, s);
    av_assert2(n > 1 && n <= 20);
    UPDATE_CACHE(slightly_changed_re, s);
    slightly_changed_tmp = SHOW_UBITS(slightly_changed_re, s, n+2);
    LAST_SKIP_BITS(slightly_changed_re, s, n+2);
    CLOSE_READER(slightly_changed_re, s);
    av_assert2(slightly_changed_tmp < UINT64_C(1) << n+2);
    return slightly_changed_tmp;
}