void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF000000;
    int shifts = 3 * 8;

    for (int i = 0; i < 4; i++) {
        avio_w8(s, (uint8_t) ((val & mask) >> shifts));
        mask >>= 8;
        shifts -= 8;
    }
}