
// Variant 1
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(; n > 0; --n){
        if (8 == s->bit_index)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(++s->buf) = 0;
        }
        *s->buf |= (val << (7 - s->bit_index));
        ++s->bit_index;
    }
}

// Variant 2
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    do{
        if (s->bit_index == 8)
        {
            *(++s->buf) = 0;
            s->bit_index = ((*s->buf) == 0xff);
        }
        *s->buf |= (val << (7 - s->bit_index));
    } while (s->bit_index++, --n > 0);
}

// Variant 3
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    while (n--){
        if (s->bit_index == 8)
        {
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            *(s->buf+1) = 0;
            s->buf++;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

The variants differ in the control and structure of their loops. However, they retain functionality with regard to writing computed bit (granular) values into a buffer of an encoder instance, which can then be compressed using image compression algorithms in JPEG2000 formatting standards. In JPEG2000 encoding, a contextually adapted binary arithmetic coding is applied, whereupon importance classification is assigned to bitplane data. Compression is achieved by constructing a compressed bit stream containing information indicative of the significance progression of bitplanes and respective stuff bytes segregation.
