void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte1, byte2, byte3, byte4;

    byte1 = (uint8_t)(val & 0xff);
    byte2 = (uint8_t)((val >> 8) & 0xff);
    byte3 = (uint8_t)((val >> 16) & 0xff);
    byte4 = (uint8_t)(val >> 24);

    avio_w8(s, byte4);
    avio_w8(s, byte3);
    avio_w8(s, byte2);
    avio_w8(s, byte1);
}