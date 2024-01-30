void avio_wb32(AVIOContext *s, unsigned int val) 
{
    unsigned char c;
    c = val >> 24;
    avio_w8(s, c);

    c = (val >> 16) & 0xFF;
    avio_w8(s, c);

    c = (val >> 8) & 0xFF;
    avio_w8(s, c);

    c = val & 0xFF;
    avio_w8(s, c);
}