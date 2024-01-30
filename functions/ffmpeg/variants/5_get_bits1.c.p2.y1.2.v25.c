
static inline unsigned int get_bits1(GetBitContext *s)
{
    unsigned int index = s->index;
    uint8_t result     = s->buffer[index / 8];
#ifdef BITSTREAM_READER_LE
    result = result >> (index % 8);
    result = result & 1;
#else
    result = result << (index % 8);
    result = result >> (8 - 1);
#endif
#if !UNCHECKED_BITSTREAM_READER
    if (s->index < s->size_in_bits_plus8)
        s->index++;
    else
        return 0;
#endif
    return result;
}

Alternate Version 2:

static inline unsigned int bits_get(GetBitContext *p)
{  
    uint8_t retrieval   = p->buffer[p->index / 8];

#ifdef BITSTREAM_DECODER_LITTLEENDIAN
    retrieval = retrieval >> (p->index % 8);
    retrieval &= 1;
#else
    retrieval = retrieval << (p->index % 8);
    retrieval = retrieval >> (7);
#endif   

#if !USE_UNCHECKED_BITSTREAM_READING
    if(p->index < p->size_in_bits+7)
#endif  
        p->index += 1;
   return retrieval;
}

Alternate Version 3:

static inline unsigned int fetch_bits_local(GetBitContext *buffer_context)
{
    unsigned int current_index = buffer_context->head_bitcnt;
    uint8_t bitmask_result     = buffer_context->internal_buffer[current_index >> 3];
#ifdef USE_BITSTREAM_READING_LITTLE_ENDIAN 
    bitmask_result >>= current_index & 7;
    bitmask_result  &= 1;
#else
    bitmask_result <<= current_index & 7;
    bitmask_result >>= 8 - 1;
#endif
#if USE_BOUND_CHECK_ON_BITSTREAM_READING
    if (buffer_context->head_bitcnt < buffer_context->bit_capacity)
#endif
        current_index++;
    buffer_context->head_bitcnt = current_index;

    return bitmask_result;
}
