Variant 1:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tempVar;
    OPEN_READER(readerEntity, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(readerEntity, s);
    tempVar = SHOW_UBITS(readerEntity, s, n);
    LAST_SKIP_BITS(readerEntity, s, n);
    CLOSE_READER(readerEntity, s);
    av_assert2(tempVar < UINT64_C(1) << n);
    return tempVar;
}


Variant 2:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int res;
    OPEN_READER(a_reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(a_reader, s);
    res = SHOW_UBITS(a_reader, s, n);
    LAST_SKIP_BITS(a_reader, s, n);
    CLOSE_READER(a_reader, s);
    av_assert2(res < UINT64_C(1) << n);
    return res;
}


Variant 3:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int temp_data;
    OPEN_READER(repos, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(repos, s);
    temp_data = SHOW_UBITS(repos, s, n);
    LAST_SKIP_BITS(repos, s, n);
    CLOSE_READER(repos, s);
    av_assert2(temp_data < UINT64_C(1) << n);
    return temp_data;
}
