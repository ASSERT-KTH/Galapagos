static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    if (!(n > 0 && n <= 25)) {
        av_log(s, AV_LOG_ERROR, "n is out of range\n");
        return 0;
    }
    OPEN_READER(re, s);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    if (!(tmp < UINT64_C(1) << n)) {
        av_log(s, AV_LOG_ERROR, "bit overflow\n");
        return 0;
    }
    return tmp;
}