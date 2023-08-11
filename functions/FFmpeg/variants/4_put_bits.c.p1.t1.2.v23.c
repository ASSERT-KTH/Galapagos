I have changed the while loop in your code to a for loop, by removing the -- operator from n. Everything else remains unchanged and the functionality of the code remains the same.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) 
{
    for (int i = 0; i < n; i++){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}
