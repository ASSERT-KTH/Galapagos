Variant 1:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    for(; n > 0; --n) 
    {
        res = res << 1;
        if (s->bit_index == 0) 
        {
            s->bit_index = 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        --s->bit_index;
        res |= (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return res;
}


Variant 2:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    do 
    {
        res = (res * 2) + ((bytestream2_peek_byte(&s->g) >> --s->bit_index) & 1);
        if (s->bit_index == 0) 
        {
            s->bit_index = 7 + !(bytestream2_get_byte(&s->g) == 0xFFu);
        }
    } while (--n);

    return res;
}


Variant 3:

static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;

    while (n--) 
    {
        res = res * 2;
        s->bit_index--;

        if (!s->bit_index) 
        {
            s->bit_index += 7 + (bytestream2_get_byte(&s->g) != 0xFFu);
        }

        res += (bytestream2_peek_byte(&s->g) >> s->bit_index) & 1;
    }

    return res;
}

