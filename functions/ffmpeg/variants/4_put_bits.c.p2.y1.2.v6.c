Here's a transformation which avoids directly incrementing pointers. Instead, it increments an offset which is added to the pointer, with the corresponding adjustments made to buffer updates. Still, it preserves functionality of the original function:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    size_t offset = 0;
    
    while (n-- > 0)
    {
        if (s->bit_index == 8) 
        {
            s->bit_index = *(s->buf+offset) == 0xff;
            offset++;                   
            s->buf[offset] = 0;
        }
        *(s->buf+offset) |= val << (7 - s->bit_index++);
    }
}
