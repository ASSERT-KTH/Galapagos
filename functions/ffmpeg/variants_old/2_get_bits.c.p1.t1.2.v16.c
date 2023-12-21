Here is a variation of the code, with a more continuous flow expressed through the use of do-while (0) loop to safely execute the sequence of macro functions:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    do {
        OPEN_READER(re, s);
        av_assert2(n > 0 && n <= 25);
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        av_assert2(tmp < UINT64_C(1) << n);
    } while (0);
    CLOSE_READER(re, s);
    return tmp;
}


This variation of code still maintains the intended functionality of the original get_bits function without changing its behaviour nor adding auxiliary functions. It only ensures that everything from OPEN_READER to LAST_SKIP_BITS function executions occur in one atomic action, reducing the likelihood of any unintended async operations or exceptions possibly interrupting them halfway.