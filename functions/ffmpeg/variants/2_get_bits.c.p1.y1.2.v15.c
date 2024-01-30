Variant 1:


static inline unsigned int get_bits_variant1(GetBitContext *s, int n)
{
    register unsigned int result_variant;
    OPEN_READER(reader_vari1, s); 
    av_assert2(n > 0 && n <= 25); 
    UPDATE_CACHE(reader_vari1, s); 
    result_variant = SHOW_UBITS(reader_vari1, s, n); 
    LAST_SKIP_BITS(reader_vari1, s, n); 
    CLOSE_READER(reader_vari1, s); 
    av_assert2(result_variant < UINT64_C(1) << n); 
    return result_variant; 
}


Variant 2:


static inline unsigned int get_bits_variant2(GetBitContext *s, int n)
{
    register unsigned int tmp_variant;
    av_assert2(n > 0 && n <= 25);
    OPEN_READER(rb, s);
    UPDATE_CACHE(rb, s);
    tmp_variant = SHOW_UBITS(rb, s, n);
    LAST_SKIP_BITS(rb, s, n);
    CLOSE_READER(rb, s);
    av_assert2(tmp_variant < UINT64_C(1) << n);
    return tmp_variant;
}


Variant 3:


static inline unsigned int get_bits_variant3(GetBitContext *s, int n)
{
    register unsigned int variant_value;
    av_assert2(n > 0 && n <= 25);
    OPEN_READER(re_var3, s);
    UPDATE_CACHE(re_var3, s);
    variant_value = SHOW_UBITS(re_var3, s, n); 
    LAST_SKIP_BITS(re_var3, s, n);
    CLOSE_READER(re_var3, s);
    av_assert2(variant_value < UINT64_C(1) << n);
    return variant_value;
}
