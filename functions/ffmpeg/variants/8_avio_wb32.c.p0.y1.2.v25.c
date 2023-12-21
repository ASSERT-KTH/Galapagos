void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t bytes[4];
    for (int i = 3; i >= 0; --i) {
        bytes[i] = (uint8_t)(val & 0xFF);
        val >>= 8;
    }
    for (int i = 0; i < 4; ++i) {
        avio_w8(s, bytes[i]);
    }
}