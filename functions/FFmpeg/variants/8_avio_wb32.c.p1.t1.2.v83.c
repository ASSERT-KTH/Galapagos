void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t bytes[4] = {val >> 24, val >> 16, val >> 8, val};

    for (int i = 0; i < 4; i++) {
        avio_w8(s, bytes[i]);
    }
}