Variant 1:
Maintain a reference to the buffer and save one dereference operation during each loop iteration.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    uint8_t *buf_ref;
    while (n-- > 0)
    {
        if (s->bit_index == 8)
        {
            buf_ref = ++s->buf;
            s->bit_index = *buf_ref == 0xff;
            *buf_ref = 0;
        }
        else
        {
            buf_ref = s->buf;
        }

        *buf_ref |= val << (7 - s->bit_index++);
    }
}


Variant 2:
Replace the while loop with a for loop for readability and add explicit braces to the if condition.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    for(int i = 0; i < n; i++)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 8 : 0;
            *(++s->buf) = 0;
        }

        *s->buf |= val << (7 - s->bit_index++);
    }
}


Variant 3:
Remove the increment operator from the BIT shift operation for readability.

static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    while (n-- > 0)
    {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }

        int index = 7 - s->bit_index;
        *s->buf |= val << index;
        s->bit_index++;
    }
}
