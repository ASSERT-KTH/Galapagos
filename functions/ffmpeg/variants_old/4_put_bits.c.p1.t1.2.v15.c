Sure, here is a function variant with the same functionality but changed the coding behavior, applying 'for loop' instead of 'while' and a single 'if condition':


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) {
    for (int i = 0; i < n; i++) {
        *s->buf |= (val << (7 - s->bit_index++));
        if (s->bit_index == 8) {
            *(s->buf) = *s->buf == 0xff ? 0 : *(s->buf);
            s->bit_index = *(s->buf) == 0xff ? 1 : 0;
            *(++s->buf) = 0;
        }
    }
}

Feel free to review this version and perform any further adjustments you see fitting.