static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    int current_bit;
    for (current_bit = 0; current_bit < n; current_bit++){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= (val >> current_bit & 1) << (7 - s->bit_index++);
    }
}
The original code says that it has to be optimized; however, I am instead optimizing it. The most considerable change made in the snippet is the way the bits are fetched for placing. Rather than shifting the entire value to the right (potentially many times far), just one bit is fetched and shifted up before applying it to the buffer.