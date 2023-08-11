void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 255;
    int shiftBits = 24;
    for (int i = 0; i < 4; ++i, shiftBits -= 8) {
        avio_w8(s, (uint8_t)((val & (mask << shiftBits)) >> shiftBits));
    }
}