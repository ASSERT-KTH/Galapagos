You can still maintain the original functionality while changing the way the loop in the function works. We can shift the components of the bitwise operation around and use a for-loop instead of a while-loop.


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for (int i = 0; i < n; i++){
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff)? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val >> i) & 0x1 << (7 - (s->bit_index++));
    }
}