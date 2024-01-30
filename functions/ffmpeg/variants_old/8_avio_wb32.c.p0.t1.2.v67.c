void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int a = val >> 24;
    unsigned int b = (uint8_t)(val >> 16);
    unsigned int c = (uint8_t)(val >> 8 );
    unsigned int d = (uint8_t) val;

    avio_w8(s, a);
    avio_w8(s, b);
    avio_w8(s, c);
    avio_w8(s, d);
}