static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int retval = 0;
    int bit_index_restore;
    unsigned mask;
 
    while (n --> 0) 
    {
        retval = retval << 1;
        
        if (s->bit_index == 0)
        {
            s->bit_index = 8 - ((bytestream2_get_byte(&s->g) == 0xFFu) == false);
        }           
         
        bit_index_restore = --(s->bit_index);
        mask = bytestream2_peek_byte(&s->g) >> bit_index_restore;
        retval = retval | (mask & 1);
    }

    return retval;
}