static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            *(s->buf) = (*s->buf == 0xff) ? 1 : 0;
            s->