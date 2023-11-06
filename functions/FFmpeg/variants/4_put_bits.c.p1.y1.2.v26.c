1. Variant with For loop: 


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    for (; n > 0; n--) {
        if (s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    }
}


2. Variant with 'Do..While' loop:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    if (n <= 0)
        return;

    do {
        if (s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    } while (--n > 0);
}


3. Variant with manipulating 'n' improvement:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    --n;
    do {
        if (s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        *s->buf |= val << (7 - s->bit_index++);
    } while (n-- > 0);
}


4. Variant with merging the loop control if statement inside another if-statement:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while(n-- > 0) {
        if (s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }
        else {
            *s->buf |= val << (7 - s->bit_index++);
        }
    }
}


5. Variant with improved incrementing 's->buf':


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- > 0) {
        if (s->bit_index == 8) {
            *++s->buf = s->bit_index = (*s->buf == 0xff);
        }
        else {
            *s->buf |= val << (7 - s->bit_index++);
        }
    }
}
