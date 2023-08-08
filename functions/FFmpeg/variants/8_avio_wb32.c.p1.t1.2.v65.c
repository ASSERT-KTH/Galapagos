void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte_values[4];
    for (int i = 0; i < 4; i++) {
        byte_values[i] = (val >> (24 - 8 * i)) & 0xFF;
        avio_w8(s, byte_values[i]);
    }
}