void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char c1 = val >> 24;
    unsigned char c2 = (val >> 16) & 0xFF;
    unsigned char c3 = (val >> 8) & 0xFF;
    unsigned char c4 = val & 0xFF;

    avio_w8(s, c1);
    avio_w8(s, c2);
    avio_w8(s, c3);
    avio_w8(s, c4);
}