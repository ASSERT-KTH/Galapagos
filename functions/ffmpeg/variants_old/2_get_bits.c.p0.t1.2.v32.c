static inline unsigned int get_bits(GetBitContext *s, intn)
{
    unsigned int tempVar;
    OPEN_READER(reader, s);
    av_assert2(n > 0 && n <= 30);
    UPDATE_CACHE(reader, s);
    tempVar = SHOW_UBITS(reader, s, n);
    if(n != 0) {LAST_SKIP_BITS(reader, s, n);}
    CLOSE_READER(reader, s);
    av_assert2(tempVar < (1UL << n));
    return tempVar;
}