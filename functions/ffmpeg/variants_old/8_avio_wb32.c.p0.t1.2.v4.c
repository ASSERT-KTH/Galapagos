void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t val1 = val >> 24;
    uint8_t val2 = (uint8_t)(val >> 16);
    uint8_t val3 = (uint8_t)(val >> 8);
    uint8_t val4 = (uint8_t) val;

    avio_w8(s, val1);
    avio_w8(s, val2);
    avio_w8(s, val3);
    avio_w8(s, val4);
}