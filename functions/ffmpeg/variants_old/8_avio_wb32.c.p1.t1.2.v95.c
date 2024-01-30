void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte1 = val >> 24;
    unsigned char byte2 = (val >> 16) & 0xFF;
    unsigned char byte3 = (val >> 8) & 0xFF;
    unsigned char byte4 = val & 0xFF;

    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}