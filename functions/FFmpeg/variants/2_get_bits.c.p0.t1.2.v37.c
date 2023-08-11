static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int updatedValue;
    OPEN_READER(readCtx, s);
    av_assert2(n > 0 && n <= 25);  
    UPDATE_CACHE(readCtx, s);  
    updatedValue = SHOW_UBITS(readCtx, s, n);  
    int scaledN = n > 0 ? n: 1;
    LAST_SKIP_BITS(readCtx, s, scaledN);
    CLOSE_READER(readCtx, s);
    av_assert2(updatedValue < UINT64_C(1) << scaledN);
    return updatedValue;
}