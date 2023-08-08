static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for (; n > 0; n--){
        if (s->bit_index == 8){
            s->bit_index = (*s->buf == 0xff) ? 0 : s->bit_index;
            *(s->buf++) = 0;
        }
        *(s->buf) |= (val % 2) << (7 - (s->bit_index++));
        val >>= 1;
    }
}