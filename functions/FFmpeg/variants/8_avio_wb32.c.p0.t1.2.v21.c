void avio_wb32(AVIOContext *s, unsigned int val) 
{
    unsigned int byte1 = val >> 24;
    unsigned int byte2 = (val >> 16) & 0xff;
    unsigned int byte3 = (val >> 8) & 0xff;
    unsigned int byte4 = val & 0xff;

    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}