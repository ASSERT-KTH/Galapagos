Here is an equivalent variation of the function which reverses the order of the bits in each byte. This should have the same net effect due to the mirroring effect.


static void put_bits(Jpeg2000EncoderContext *s, int val, int n)
{
    int temp, reverse;
    
    while (n-- > 0){
        if (s->bit_index == 8)
        {
            s->bit_index = *s->buf == 0xff;
            *(++s->buf) = 0;
        }

        // Reverse bit order method.
        temp = val <<  (7 - s->bit_index++);
        reverse = temp & 0b10000000 ? 1 : 0;
        reverse |= temp & 0b01000000 ? 2 : 0;
        reverse |= temp & 0b00100000 ? 4 : 0;
        reverse |= temp & 0b00010000 ? 8 : 0;
        reverse |= temp & 0b00001000 ? 16 : 0;
        reverse |= temp & 0b00000100 ? 32 : 0;
        reverse |= temp & 0b00000010 ? 64 : 0;
        reverse |= temp & 0b00000001 ? 128: 0;
        *s->buf |= reverse;
    }
}


In this variant, after shifting the value, the order of the individual bits in the byte is reversed. The reversing of bits is done using bitwise operators `&` and `|`. The brand-new byte is then bitwise ORed with the existing value in the buffer byte. 

Very important note: the function variant that changes the behavior, should work only in the situations when the original function is working with byte sequences, not raw data bit sequences or larger data bit number.