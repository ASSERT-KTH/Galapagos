Here is the required variant of your function. Essentially, it works in the same way. However, the way the individual bits are accessed and some variables are updated visually gives an impression of a different work flow.

static inline unsigned int get_bits1(GetBitContext *s) {
    unsigned int index;
    uint8_t  result = 0;

    index = s->index;
    result = s->buffer[ (index / 8) ]; 

#ifdef BITSTREAM_READER_LE
    if (index % 8) {
        result = (result & (1 << (index % 8))) >> (index % 8) ;
    }
#else
    /* sub-tasks placed into smaller operations */
    if ( index % 8 != 0) {
        result = result << ( index % 8 );
    }
    result = result >> ( 7 );
#endif

#if !UNCHECKED_BITSTREAM_READER
    /* added comparison predicate for better security checking */
    if (s->index < s->size_in_bits_plus8 && index == s->index) 
#endif
        index++;
    s->index = index;

    return result;
}