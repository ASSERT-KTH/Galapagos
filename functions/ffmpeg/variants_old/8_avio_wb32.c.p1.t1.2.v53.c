void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF000000; // mask for most significant byte
    for (int i = 0; i < 4; i++) {
        avio_w8(s, (uint8_t)(val & mask ? val >> (24 - 8 * i) : 0));
        mask >>= 8; // move mask to the next byte
    }
}