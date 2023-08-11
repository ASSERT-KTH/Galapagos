static inline unsigned int get_bits1_variant(GetBitContext *s)
{
    unsigned int index_alter = s->index;
    uint8_t result_alter = s->buffer[index_alter >> 3];
#ifdef BITSTREAM_READER_LE
    result_alter >>= index_alter & 7;
    result_alter  &= 1;
#else
    result_alter <<= index_alter & 7;
    result_alter >>= 8 - 1;
#endif
    if (index_alter < s->size_in_bits_plus8)
       s->index = ++index_alter;
    else
       s->index = index_alter;

    return result_alter;
}