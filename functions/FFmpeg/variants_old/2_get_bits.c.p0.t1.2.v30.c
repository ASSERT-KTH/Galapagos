static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp = 0;
    OPEN_READER(rdr, s);
    if(n > 0 && n <= 25) {
        UPDATE_CACHE(rdr, s);
        temp = SHOW_UBITS(rdr, s, n);
        LAST_SKIP_BITS(rdr, s, n);
    }  
    CLOSE_READER(rdr, s);
    
    if (temp < (UINT64_C(1) << n)) {
        return temp;
    } else {
        return 0;
    }
}