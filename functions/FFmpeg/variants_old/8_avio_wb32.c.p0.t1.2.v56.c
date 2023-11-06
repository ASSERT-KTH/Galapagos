void avio_wb32(AVIOContext *s, unsigned int val)
{
    int shift = 24;
    for (int i = 0; i < 4; i++) {
        avio_w8(s, (uint8_t)(val >> shift));
        shift -= 8;
    }
}