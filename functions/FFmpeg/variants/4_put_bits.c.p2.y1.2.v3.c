static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{ 
    for(int i = n; i > 0; --i){
        *(s->buf) |= ((s->bit_index == 8)  ? s->bit_index = *s->buf !=0, ++(s->buf), 0 : val << (7 - s->bit_index++));
    }
}