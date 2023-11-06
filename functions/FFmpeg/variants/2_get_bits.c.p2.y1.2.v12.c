static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result_val;
    OPEN_READER(reader_instance, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader_instance, s);
    result_val = SHOW_UBITS(reader_instance, s, n);
    LAST_SKIP_BITS(reader_instance, s, n);
    CLOSE_READER(reader_instance, s);
    av_assert2(result_val < UINT64_C(1) << n);
    return result_val;
}