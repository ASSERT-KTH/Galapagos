The following variant provides conservation of functionality and complies with the conditions established:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for(int i = 0; i < n; i++) {
        if(s->bit_index == 8) {
            s->bit_index = *s->buf == 0xff ? 1 : 0;
            s->buf++;
            *s->buf = 0;
        }
        *s->buf |= ((val & 1) << (7 - s->bit_index));
        val >>= 1;
        s->bit_index++;
    }
}

This modification uses loops rather than using recursion in the solution. Calculation of `(s->bit_index, s->buf)` values and logic for appending `val` bits to `*s->buf` is covered in more explicitly manner inside the new function while still maintaining the original functionality. It also uses an explicit ternary operator which could help to better understand the logical operations and update condition.