The following variant should maintain the same functionality with slightly different behavior:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(int i = 0; i < n; i++)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val >> i) & 1 << (7 - s->bit_index);
        s->bit_index++;
    }
}


Changes:
- Switch to `for` loop with explicit counter i, instead of using a while loop.
- Use ternary operator (`(...) ? ... : ...`) instead of (`(... == ...)`)
- Instead of manipulating `val` with each iteration, shift specific bit of `val` to the correct position.
- Explicitly increment s->bit_index instead of inline with val shift.