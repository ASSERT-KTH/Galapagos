static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    do {
        s->bit_index = s->bit_index == 8 ? *s->buf == 0xff : s->bit_index;
        s->buf = s->bit_index != 8 ? s->buf : ++s->buf;
        s->buf = s->bit_index != 8 ? s->buf : (int*)((*s->buf) = 0);
        *s->buf = *s->buf | (val << (7 - (s->bit_index++)));
    } while(--n > 0);
}