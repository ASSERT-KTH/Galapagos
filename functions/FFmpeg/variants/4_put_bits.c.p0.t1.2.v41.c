static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n != 0){
        if (s->bit_index >= 8) // Instead of == checking for >= provides safer checking.
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0; // Much clearer logic with ternary operator.
            *(++s->buf) = 0;
        }
        *s->buf |= (val & (1 << (7 - s->bit_index))) != 0; // & operation can be described clearer.
        s->bit_index++;
        n--;
    }
}