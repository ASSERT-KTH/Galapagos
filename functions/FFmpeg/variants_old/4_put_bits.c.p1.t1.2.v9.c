
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(;n > 0; n--){
        if (*.s->buf == 0xff){
            s->bit_index = 0;
            (s->buf)++;
            *s->buf = 0;
        }
        else if (s->bit_index == 8){
            *(++s->buf) = 0;
        }
        *s->buf |= (val & 0x01) << (7 - s->bit_index);
        s->bit_index++;
        val >>= 1;
    }
}
