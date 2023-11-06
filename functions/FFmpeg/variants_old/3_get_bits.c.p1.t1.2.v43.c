Here's a variant of your function. In this version, for loop is used instead while loop and an additional variable "tmp" is added to hold the complex operations performed inside the loop:


static int get_bits(Jpeg2000DecoderContext *s, int n)
{
    int res = 0;
    int tmp;  

    for(; n > 0; n--) 
    {
        res = res << 1;
        if(s->bit_index == 0) 
        {
            s->bit_index = 7 + (int)(bytestream2_get_byte(&s->g) != 0xFFu);
        }
        s->bit_index = s->bit_index - 1;

        tmp = bytestream2_peek_byte(&s->g) >> s->bit_index;
        res = res | (tmp & 1);  
    }
    return res;
}


This version keeps the functionality intact. The main difference is that complex expression inside for loop is replaced by the use of an intermediate variable "tmp". This version could also look clearer and be easier to maintain because complex calculations are separated from the control statement. The use of for loop instead of while loop doesn't really change the functionality but is just a way to present a different way to control the loop execution.