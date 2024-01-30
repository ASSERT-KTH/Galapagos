void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int byte1 = val >> 24;
    unsigned int byte2 = (uint8_t)(val >> 16);
    unsigned int byte3 = (uint8_t)(val >> 8);
    unsigned int byte4 = (uint8_t) val;

    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}