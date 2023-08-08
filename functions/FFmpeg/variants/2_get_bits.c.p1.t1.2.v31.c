static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp, result;
    int check_val;
    OPEN_READER(re, s);

    check_val = n>0 && n<=25;
    av_assert2(check_val);
  
    if(!check_val) {
        return -1; // This is to check valid input
    }

    UPDATE_CACHE(re, s);
    result = SHOW_UBITS(re, s, n);
    tmp = result;
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);

    av_assert2(tmp < byexp(n)); //byexp is defined as: ULONG_C(1) << n
    return result;
}