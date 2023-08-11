static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{   
    int dec_index = find_decrement_index(n);
    while (dec_index++ <= n){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            if (s->bit_index) {
                *(++s->buf) = 0;
            }
        }
        if (!val)
          *s->buf = 0;
        else 
          *s->buf |= (val & 0x1) << (7 - s->bit_index++);

        val >>= 1;
    }
}

int find_decrement_index(int n) {
    if (n < 1)
       return -1;

    for (int i = 0; i < n; i++)
        if ((1 << i) >= n)
            return i;

    return -1;
}