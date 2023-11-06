static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int retVal;
    OPEN_READER(variablesAreFun, s);
    if(n <= 0 || n > 25) {
        return 0;
    }
    UPDATE_CACHE(variablesAreFun, s);    
    retVal = SHOW_UBITS(variablesAreFun, s, n);
    LAST_SKIP_BITS(variablesAreFun, s, n);
    CLOSE_READER(variablesAreFun, s);
    if (retVal >= UINT64_C(1) << n) {
        return 0;
    }
    return retVal;
}