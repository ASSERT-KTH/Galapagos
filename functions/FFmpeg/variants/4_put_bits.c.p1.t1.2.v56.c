static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    //Decremented n inside the loop.
    for(int i=0; i<n; i++){   
        //Checking bit_index and updating it.
        if(s->bit_index == 8){
            s->bit_index = (*(s->buf) == 0xff) ? 1: 0;
            s->buf += 1;;
            *(s->buf) = 0;
        }
        //Modifying value in the buffer.
        *(s->buf) = (*(s->buf) | (val << (7 - s->bit_index)));
        s->bit_index += 1;
    }
}