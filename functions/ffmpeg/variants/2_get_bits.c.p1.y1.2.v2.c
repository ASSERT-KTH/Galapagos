/*
Variant 1
*/
static inline unsigned int get_bits(GetBitContext *input, int num)
{
    register unsigned int result;
    OPEN_READER(reader, input);
    av_assert2(num > 0 && num <= 25);
    UPDATE_CACHE(reader, input);
    result = SHOW_UBITS(reader, input, num);
    LAST_SKIP_BITS(reader, input, num);
    CLOSE_READER(reader, input);
    av_assert2(result < UINT64_C(1) << num);
    return result;
}

/*
Variant 2
*/
static inline unsigned int get_bits(GetBitContext *current, int val)
{
    register unsigned int capture;
    OPEN_READER(ctx, current);
    av_assert2(val > 0 && val <= 25);
    UPDATE_CACHE(ctx, current);
    capture = SHOW_UBITS(ctx, current, val);
    LAST_SKIP_BITS(ctx, current, val);
    CLOSE_READER(ctx, current);
    av_assert2(capture < UINT64_C(1) << val);
    return capture;
}

/*
Variant 3
*/
static inline unsigned int get_bits(GetBitContext *src, int length)
{
    register unsigned int value;
    OPEN_READER(re_context, src);
    av_assert2(length > 0 && length <= 25);
    UPDATE_CACHE(re_context, src);
    value = SHOW_UBITS(re_context, src, length);
    LAST_SKIP_BITS(re_context, src, length);
    CLOSE_READER(re_context, src);
    av_assert2(value < UINT64_C(1) << length);
    return value;
}