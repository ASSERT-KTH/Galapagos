void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte1 = val >> 24;
    uint8_t byte2 = (uint8_t)(val >> 16);
    uint8_t byte3 = (uint8_t)(val >> 8 );
    uint8_t byte4 = (uint8_t) val;

    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}