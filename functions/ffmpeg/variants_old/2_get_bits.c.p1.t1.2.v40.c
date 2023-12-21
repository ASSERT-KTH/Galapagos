static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(initial_bit_length, s);
    /* Debug assert to assure valid input "n" within stipulated limit 0 < n <= 25 */
    av_assert2(n>0 && n<=25); 
    /* Update the bit cache from the stream for further steps */
    UPDATE_CACHE(initial_bit_length, s); 
    /* Retrieve "n" number of Bits from bit cache without altering it */
    result = SHOW_UBITS(initial_bit_length, s, n);
    /* Skip past the already read bits */
    LAST_SKIP_BITS(initial_bit_length, s, n);
    /* Stop reading the cached bit values */
    CLOSE_READER(initial_bit_length, s);
    /* Ensure solution constraint: 0 <= Result === acquired bits < 2^n */
    av_assert2(result < UINT64_C(1) << n);
    return result;
}