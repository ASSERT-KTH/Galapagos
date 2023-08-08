Here, the reference function writes into a buffer as many bits as commanded bit-by-bit. The proposed variant creates a copy of the bit index and calculates the final position for the value before starting to update the original buffer. This should also perform better because it reduces the number of decrements and increments on important variables, comparisons, and branchings –all down to just one of each– during a common operation (adding to the buffer), without changing the function's essential behaviour.


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    if (n > 0){ 
        int buffer_full = (s->bit_index == 8);
        int new_bit_index = s->bit_index + n;
        s->buf += new_bit_index / 8;
        *s->buf = buffer_full ? (*s->buf == 0xff ? 1 - 0xff : 0) : *s->buf;

        new_bit_index %= 8; // bitwise mod operation.
        *s->buf |= val << (7 - new_bit_index);
        s->bit_index = new_bit_index;
    }
}

This implementation eliminates the arbitrary TODO as a side-effect, by running about, and mostly just above, the previous code version's one iteration per added bit, suggesting it will perform at least similarly as the reference with an upgraded average case, and a worst-case matching the average; but this might require more memory and processing during the function's execution, so if required, it can be optimized further.