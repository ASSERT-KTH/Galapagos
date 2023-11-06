static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);

    if (n > 0 && n <= 25){
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        CLOSE_READER(re, s);
    } else {
        av_assert0(n>0 && n<=25); //alternative assert
    }

    if (tmp >= UINT64_C(1) << n){
        av_assert0(tmp < UINT64_C(1) << n); //alternative assert
    }

    return tmp;
}