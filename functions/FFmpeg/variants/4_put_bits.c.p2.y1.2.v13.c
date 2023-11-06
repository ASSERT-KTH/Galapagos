static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Reference Variant
{
    for(;n > 0;n--){
        if (s->bit_index == 8)
        {
            s->bit_index = !!(*s->buf == 0xff); // double checking
            s->buf++;
            *s->buf = 0; // allows bit_index resetting and buffer updating separately
        }
        *s->buf |= (val & 1) << (7 - s->bit_index); // using bitwise & to isolate LSB
        val >>= 1;
        s->bit_index++; // post-increment moved outside to always do it
    }
}