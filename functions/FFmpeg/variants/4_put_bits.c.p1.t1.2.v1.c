static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    int curr_val;

    for (int i = 0; i < n; i++)
    {
        if (s->bit_index == 8){
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }

        curr_val = val << (7 - s->bit_index);
        *s->buf = (*s->buf) | curr_val;
        s->bit_index++;

    }
}