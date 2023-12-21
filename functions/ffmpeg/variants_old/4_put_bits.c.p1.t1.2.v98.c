static void put_bits(Jpeg2000EncoderContext *s, int val, int n) //data representation method with bitwise manipulation
{
    int shiftAmount; 

    for (; n > 0; n--)
    {
        shiftAmount = 7 - s->bit_index; 
        if (s->bit_index == 8)
        {
            s->bit_index= 0;
            if(*s->buf == 0xff){
                s->bit_index = 1;
            }
            s->buf++;
            *s->buf = 0;
        }
        *s->buf = (*s->buf & (~(1 << shiftAmount))) | ((val & 0x1) << shiftAmount); //Encode with bitwise manipulation
        s->bit_index++; 
        val = val >> 1;   
     }
}