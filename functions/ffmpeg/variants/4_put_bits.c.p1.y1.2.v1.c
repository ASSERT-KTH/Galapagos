Variant 1:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    do {
        int hasData = s->bit_index == 8;
        s->buf = hasData ? s->buf + 2 : s->buf + 1;
        *s->buf |= val << (7 - (s->bit_index += hasData ? 0 : 1));
        n--;
    } while (n > 0);
}


Variant 2:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    for (; n > 0; n--) {
        int bitIndexEight = s->bit_index == 8;
        s->bit_index = bitIndexEight ? 0 : s->bit_index;
        s->buf = s->buf + bitIndexEight;
        if (bitIndexEight) 
            *s->buf = 0;
        *s->buf |= val << (7 - s->bit_index++);
    }
}


Variant 3:

static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    while (n-- > 0){
        int bit_index_next = s->bit_index + 1;
        int overflow_flag = (bit_index_next == 8) ? 0xff : 0x00;
        *s->buf |= val << (7 - s->bit_index);
        ++s->buf &= overflow_flag;
        s->bit_index = s->bit_index % 8 + 1;
    }
}
