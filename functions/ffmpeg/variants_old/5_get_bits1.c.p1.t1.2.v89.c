Here is a simple variation of the original function. This doesn't change its signature or use auxiliary or helper functions and maintains the original functionality. Here I've avoided some conditional constructs (mostly #ifdef and #if) and simplified some bitwise operations.


static inline unsigned int get_bits1_variant(GetBitContext* s) {
    unsigned int index = s->index;
    uint8_t result = s->buffer[index / 8];
    
    int offset = index % 8;

#ifdef BITSTREAM_READER_LE
    result = (result >> offset) & 1;
#else
    result = (result << offset) >> 7;
#endif    

    if(++s->index >= s->size_in_bits_plus8) {
        s->index = index;
    }

    return result;
}

In this variant:

Reduced use of conditional constructs by replacing (index >> 3) with (index / 8) and (index & 7) with (index % 8), because they yield the same results. 

Removed the conditional compilation directive for index underflow checking, replaced it with a simple if statement that rolls back 's->index' whenever it exceeds 's->size_in_bits_plus8' limit.

Shifts the result before applying AND operation on BITSTREAM_READER_LE scenario (unlike the simultaneous application of both operations in your original function)

This assumes that the behavior of BITSTREAM_READER_LE, BITSTREAM_READER_BE and UNCHECKED_BITSTREAM_READER are hardware or compile-time controlled, hence not used any run-time conditional statement considering those.