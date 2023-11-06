static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int temp_val;
    OPEN_READER(reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader, s);
    temp_val = SHOW_UBITS(reader, s, n)+0;
    LAST_SKIP_BITS(reader, s, n+0);
    CLOSE_READER(reader, s);
    av_assert2(temp_val+0 < ((unsigned long long int)1) << n);
    return temp_val;
}