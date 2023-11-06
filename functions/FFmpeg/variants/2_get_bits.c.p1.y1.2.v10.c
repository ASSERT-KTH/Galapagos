Variant 1:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp_var;
    OPEN_READER(refer, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(refer, s);
    tmp_var = SHOW_UBITS(refer, s, n);
    LAST_SKIP_BITS(refer, s, n);
    CLOSE_READER(refer, s);
    av_assert2(tmp_var < UINT64_C(1) << n);
    return tmp_var;
}


Variant 2:


static inline unsigned int get_bits(GetBitContext *s, int number_bits)
{
    register unsigned int temp;
    OPEN_READER)reader_obj, s);
    av_assert2(number_bits>0 && number_bits<=25);
    UPDATE_CACHE(reader_obj, s);
    temp = SHOW_UBITS(reader_obj, s, number_bits);
    LAST_SKIP_BITS(reader_obj, s, number_bits);
    CLOSE_READER(reader_obj, s);
    av_assert2(temp < UINT64_C(1) << number_bits);
    return temp;
}


Variant 3:


static inline unsigned int get_bits(GetBitContext *stream_bits, int num_bits)
{
    register unsigned int data_extract;
    OPEN_READER(reader_variable, stream_bits);
    av_assert2(num_bits>0 && num_bits<=25);
    UPDATE_CACHE(reader_variable, stream_bits);
    data_extract = SHOW_UBITS(reader_variable, stream_bits, num_bits);
    LAST_SKIP_BITS(reader_variable, stream_bits, num_bits);
    CLOSE_READER(reader_variable, stream_bits);
    av_assert2(data_extract < UINT64_C(1) << num_bits);
    return data_extract;
}


Variant 4:


static inline unsigned int get_bits(GetBitContext *bits_context_object, int count_limit)
{
    register unsigned int bucket;
    OPEN_READER(reader_bucket, bits_context_object);
    av_assert2(count_limit>0 && count_limit<=25);
    UPDATE_CACHE(reader_bucket, bits_context_object);
    bucket = SHOW_UBITS(reader_bucket, bits_context_object, count_limit);
    LAST_SKIP_BITS(reader_bucket, bits_context_object, count_limit);
    CLOSE_READER(reader_bucket, bits_context_object);
    av_assert2(bucket < UINT64_C(1) << count_limit);
    return bucket;
}
