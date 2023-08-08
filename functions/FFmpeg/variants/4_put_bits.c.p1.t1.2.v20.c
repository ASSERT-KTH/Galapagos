Here's a slight variant of the initial function that gives the exact same output:


static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
    for (int i = 0; i < n; i++){
        if (s->bit_index == 8){
            (*s->buf)++;
            s->bit_index = (*s->buf == 0xff) ? 1 : 0;
            if (s->bit_index) *s->buf = 0;
        }
        *s->buf |= (val & 1) << (7 - s->bit_index);
        val >>= 1;
        s->bit_index++;
    }
}


In this modified version, a for-loop is used instead of a while loop. The logic for resetting the buffer when s->bit_index achieves 8, and incrementing the buffer, is maintained but rephrased to firstly increment (*s->buf) and then potentially reset *s->buf to 0 depending on *s->buf equalling 0xff - only a slight rewriting of the code’s logic to produce the same functionality.

Shifting of the input value (val) to align next bit with the buffer (s->buf) takes place inside the loop to affect appending `val` to `s->buf` across each iteration (it’s bit-wise edging down val's binary representation during the loop), which – again – polarizes how the code’s logic is structurally presented.