void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte1 = (unsigned char) (val >> 24);
    unsigned char byte2 = (unsigned char) (val >> 16) & 0xFF;
    unsigned char byte3 = (unsigned char) (val >> 8) & 0xFF;
    unsigned char byte4 = (unsigned char) val & 0xFF;
    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}