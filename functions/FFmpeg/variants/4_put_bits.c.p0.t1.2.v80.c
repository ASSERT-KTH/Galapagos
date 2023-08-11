static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Simplified for loop
{
    for(int i = n; i > 0; i--){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(s->buf + 1) = 0;
            s->buf++;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++; // Increment at the end of loop iteration
    }
}