static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int data;
    OPEN_READER(reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader, s);
    data = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    av_assert2(data < UINT64_C(1) << n);
    return data;
}