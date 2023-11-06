static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(int i=0;i<n;i++){
        if (s->bit_index == 8){
            s->bit_index = *s->buf == 0xff;
            s->buf++;
            *s->buf = 0;
        }
        else{
            *s->buf |= (val & 1 << (n - (i + 1)))*((int)pow(2,(7 - s->bit_index)));
            s->bit_index++;
        }
    }
}