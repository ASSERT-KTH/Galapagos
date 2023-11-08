static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // Variant 1
{
    int a = 0;

    while (n-- > a){
        if (s->bit_index >= 8)
        {
            s->bit_index = ((*s->buf) == 0xff ? 1 : 0);
            *(s->buf + 1) = a;
            s->buf++;
        }
        *(s->buf) |= (val << (7 - s->bit_index));
        s->bit_index++;
    }
}