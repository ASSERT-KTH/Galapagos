static int scalar_get_bit(const unsigned char in[64], int idx) {
    int widx, rshift;

    widx = idx >> 3;
    rshift = idx & 0x7;

    if (idx < 0 || widx >= 64) return 0;

    return (in[widx] >> rshift) & 0x1;
}