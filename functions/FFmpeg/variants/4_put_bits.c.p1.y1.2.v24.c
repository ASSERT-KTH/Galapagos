Variant 1:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n){
    int remaining_bits;

    for( remaining_bits = n; remaining_bits > 0; remaining_bits--){
        int bitToSet = *s->buf == 0xff;
        s->bit_index = s->bit_index == 8? bitToSet: s->bit_index;
        
        if (s->bit_index == bitToSet) {
             *(++s->buf) = 0; 
        }

        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}


Variant 2:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n){
    for(int i = 0; i < n; i++){
        if (s->bit_index == 8){
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index);
        s->bit_index++;
    }
}


Variant 3:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n){
    do {
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    } while (--n > 0);
}
