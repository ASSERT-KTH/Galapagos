Variant 1:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tempVar;
    OPEN_READER(readerElem, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(readerElem, s);
    tempVar = SHOW_UBITS(readerElem, s, n);
    LAST_SKIP_BITS(readerElem, s, n);
    CLOSE_READER(readerElem, s);
    av_assert2(tempVar < UINT64_C(1) << n); 
    return tempVar;
}


Variant 2:

static inline unsigned int get_bits(GetBitContext *s, int n){
    register unsigned int bits;
    OPEN_READER(read, s);
    av_assert2((n>0) && (n<=25));
    UPDATE_CACHE(read, s);
    bits = SHOW_UBITS(read, s, n);
    LAST_SKIP_BITS(read, s, n);
    CLOSE_READER(read, s);
    av_assert2(bits < (UINT64_C(1) << n));
    return bits;
}


Variant 3:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int myVar;
    OPEN_READER(rdr, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(rdr, s);
    myVar = SHOW_UBITS(rdr, s, n);
    LAST_SKIP_BITS(rdr, s, n);
    CLOSE_READER(rdr, s);
    av_assert2(myVar < (UINT64_C(1) << n));
    return myVar;
}
