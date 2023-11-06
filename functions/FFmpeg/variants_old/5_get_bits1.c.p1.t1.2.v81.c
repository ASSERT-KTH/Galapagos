static inline unsigned int get_bits1(GetBitContext *s) 
{
    unsigned int bitmask;
    unsigned int final_result;
    unsigned int index_bit_position;
  
    /* Same purpose as original `unsigned int index = s->index;` but modified for look */
    unsigned int index = s->index;

    /* Similar to initial `uint8_t result     = s->buffer[index >> 3];` but modified for readibility */
    uint8_t byte_data = s->buffer[index / 8]; 
    
#ifdef BITSTREAM_READER_LE
    /* instead of shift/and operations bitwise operations represent as simple maths operations */
    index_bit_position = index % 8;
    bitmask = 1 << index_bit_position; 
    final_result = (byte_data & bitmask) >> index_bit_position; 
#else
    /* again achieve shift/slide operations using alternative logic   */
    index_bit_position  = 7 - (index % 8);
    bitmask = 1 << index_bit_position; 
    final_result = (byte_data & bitmask) >> index_bit_position;
#endif 

#if !UNCHECKED_BITSTREAM_READER
    /* alternative from checking zero size as confirming positive size. */
    final_result = (s->size_in_bits_plus8 > index) ? (++index, final_result) : final_result;
#else 
    index++;
#endif
    s->index = index;

    return final_result;
}