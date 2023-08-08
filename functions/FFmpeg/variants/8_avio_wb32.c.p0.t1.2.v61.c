void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte1 = val >> 24;
    unsigned char byte2 = (uint8_t)(val >> 16);
    unsigned char byte3 = (uint8_t)(val >> 8);
    unsigned char byte4 = (uint8_t)val;

    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}