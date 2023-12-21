static inline unsigned int alternate_get_bits(GetBitContext *s, int n)
{
    unsigned int new_bits;      // initialize a new unsigned int
    OPEN_READER(reader, s);     // call the OPEN_READER function
    av_assert2(n > 0 && n <= 25); // assure the number of bits is in [1, 25]

    UPDATE_CACHE(reader, s);       // update the bit context 

    new_bits = SHOW_UBITS(reader, s, n);     // store the new bit in integer var.

    LAST_SKIP_BITS(reader, s, n);    // skip the remaining bits after use

    CLOSE_READER(reader, s); // we're done processing, now closing it

    av_assert2(new_bits < UINT64_C(1) << n);
    return new_bits;   // return the selected bit
}