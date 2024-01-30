Below are three variants of the original function:

Variant 1:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;

    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);
    
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    
    CLOSE_READER(re, s);
    
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}

Your request does not make the use of the keyword `register` necessary.

Variant 2:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    int n_valid = (n>0 && n<=25) ? n : 0;

    OPEN_READER(re, s);
    av_assert2(n_valid);
    UPDATE_CACHE(re, s);
    
    tmp = SHOW_UBITS(re, s, n_valid);
    LAST_SKIP_BITS(re, s, n_valid);
    
    CLOSE_READER(re, s);
    
    av_assert2(tmp < UINT64_C(1) << n_valid);
    return tmp;
}

In this variant, variables reassigned only assume valid values. Thus, the assertion can convert 0-result values to error state if you choose not to proceed after an invalid `n`.

Variant 3:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);
    
    register unsigned int tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
        
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
   
    return tmp;
}

In this variant, the definition has been postponed until evaluation using the `tmp`. By doing this, compilers may compile more efficiently.
