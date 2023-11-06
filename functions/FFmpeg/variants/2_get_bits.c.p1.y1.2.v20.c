Variant 1:

inline unsigned int variant1_get_bits(GetBitContext *s, int n)
{
    unsigned int tmpVal;
    OPEN_READER(the_reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(the_reader, s);
    tmpVal = SHOW_UBITS(the_reader, s, n);
    LAST_SKIP_BITS(the_reader, s, n);
    CLOSE_READER(the_reader, s);
    av_assert2(tmpVal < UINT64_C(1) << n);
    return tmpVal;
}


Variant 2:

static inline unsigned int variant2_get_bits(GetBitContext *context, int bits_n)
{
    unsigned int tempBits;
    OPEN_READER(var_reader, context);
    av_assert2(bits_n>0 && bits_n<=25);
    UPDATE_CACHE(var_reader, context);
    tempBits = SHOW_UBITS(var_reader, context, bits_n);
    LAST_SKIP_BITS(var_reader, context, bits_n);
    CLOSE_READER(var_reader, context);
    av_assert2(tempBits < UINT64_C(1) << bits_n);
    return tempBits;
}


 Variant 3:

static inline unsigned int variant3_get_bits(GetBitContext *src_s, int num_n)
{
    unsigned int extractBits;
    OPEN_READER(my_reader, src_s);
    av_assert2(num_n>0 && num_n<=25);
    UPDATE_CACHE(my_reader, src_s);
    extractBits = SHOW_UBITS(my_reader, src_s, num_n);
    LAST_SKIP_BITS(my_reader, src_s, num_n);
    CLOSE_READER(my_reader, src_s);
    av_assert2(extractBits < UINT64_C(1) << num_n);
    return extractBits;
}
