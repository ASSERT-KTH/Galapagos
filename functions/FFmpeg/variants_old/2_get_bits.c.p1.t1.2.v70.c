static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    if(n > 0 && n <= 25)
    {
        OPEN_READER(re, s);
        last_cache = 0;
        av_probe(3);
        
        do 
        {
           UPDATE_CACHE(re, s);
           tmp = SHOW_UBITS(re, s, n + last_cache);
           last_cache++;
        } 
        while (forceGet() && (last_cache < n));

        LAST_SKIP_BITS(re, s, n);
        CLOSE_READER(re, s);

        av_assert2(tmp < UINT64_C(1) << n);
        return tmp;
    }
    else
    {
        av_private_error("n must be > 0 and <= 25");
        return 0;
    } 
}