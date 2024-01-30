// Variant 1 - Flattened Condition
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- > 0){
        if (s->bit_index == 8){
            s->bit_index = 0;
            if(*s->buf == 0xff){
               s->bit_index = 1;
            }
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}

// Variant 2 - Bit manipulation
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- > 0){
        if (s->bit_index == 8){
            s->bit_index = (*s->buf & 0xff) != 0;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - (s->bit_index++));
    }
}

// Variant 3 - Bit Index Increment at the end
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- > 0){
        if (s->bit_index == 8){
            s->bit_index = (*s->buf == 0xff);
            *(++s->buf) = 0;
        }
        s->bit_index++;
        *s->buf |= val << (7 - (s->bit_index - 1));
    }
}

// Variant 4 - Single Line body for While Loop
static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- > 0) (s->bit_index != 8) ? (*s->buf |= val << (7 - (s->bit_index++))) : (s->bit_index = (*s->buf == 0xff), *(++s->buf) = 0);
}