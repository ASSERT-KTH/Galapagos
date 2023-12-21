static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    do {
        int adjVal = s->bit_index == 8 ? 0xff : 0; 
        s->bit_index = ( s->bit_index == 8 ) ? *s->buf : s->bit_index;
        s->buf = ( s->bit_index == adjVal ) ? s->buf+1 : s->buf;
        *s->buf = ( s->bit_index == adjVal ) ? 0 : *s->buf;
        *s->buf |= (val << (7  - ++s->bit_index) & 0xFF);
    } while (--n > 0);
}