Variant 1:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    
    OPEN_READER(context_open, s);

    av_assert2(n > 0 && n <= 25);
    
    UPDATE_CACHE(context_open, s);

    temp = SHOW_UBITS(context_open, s, n);
    
    LAST_SKIP_BITS(context_open, s, n);
    
    CLOSE_READER(context_open, s);

    av_assert2(temp < UINT64_C(1) << n);
    
    return temp;
}


Variant 2:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int var_tmp;
    OPEN_READER(reader_var, s);
    
    av_assert2(n > 0 && n <= 25);
    
    UPDATE_CACHE(reader_var, s);
    
    var_tmp = SHOW_UBITS(reader_var, s, n);
    
    LAST_SKIP_BITS(reader_var, s, n);
    
    CLOSE_READER(reader_var, s);
    
    av_assert2(var_tmp < UINT64_C(1) << n);
    
    return var_tmp;
}


Variant 3:


static inline unsigned int get_bits(GetBitContext *bitContext, int num)
{
    register unsigned int temp_val;
    OPEN_READER(re_ctx, bitContext);
    
    av_assert2(num > 0 && num <= 25);
    
    UPDATE_CACHE(re_ctx, bitContext);
    
    temp_val = SHOW_UBITS(re_ctx, bitContext, num);
    
    LAST_SKIP_BITS(re_ctx, bitContext, num);
    
    CLOSE_READER(re_ctx, bitContext);
    
    av_assert2(temp_val < UINT64_C(1) << num);
    
    return temp_val;
}
