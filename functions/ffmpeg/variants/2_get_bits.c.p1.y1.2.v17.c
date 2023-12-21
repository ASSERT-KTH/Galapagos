Transformtation-1


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int bits_to_return;
    OPEN_READER(reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader, s);
    bits_to_return = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    av_assert2(bits_to_return < UINT64_C(1) << n);
    return bits_to_return;
}


Transformatiom-2


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int fetched_bits;
    OPEN_READER(ctx_reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(ctx_reader, s);
    fetched_bits = SHOW_UBITS(ctx_reader, s, n);
    LAST_SKIP_BITS(ctx_reader, s, n);
    CLOSE_READER(ctx_reader, s);
    av_assert2(fetched_bits< UINT64_C(1) << n);
    return fetched_bits;
}


Transformation-3


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int extracted_bits;
    OPEN_READER(bit_extractor, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(bit_extractor, s);
    extracted_bits = SHOW_UBITS(bit_extractor, s, n);
    LAST_SKIP_BITS(bit_extractor, s, n);
    CLOSE_READER(bit_extractor, s);
    av_assert2(extracted_bits< UINT64_C(1) << n);
    return extracted_bits;
}
