void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int val1 = val >> 24;
    unsigned int val2 = (uint8_t)(val >> 16);
    unsigned int val3 = (uint8_t)(val >> 8);
    unsigned int val4 = (uint8_t) val;

    avio_w8(s, val1);
    avio_w8(s, val2);
    avio_w8(s, val3);
    avio_w8(s, val4);
}