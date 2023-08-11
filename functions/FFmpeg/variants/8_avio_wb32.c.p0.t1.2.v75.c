void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int first  = val >> 24;
    unsigned int second = (uint8_t)(val >> 16);
    unsigned int third  = (uint8_t)(val >> 8);
    unsigned int fourth = (uint8_t)val;

    avio_w8(s, first);
    avio_w8(s, second);
    avio_w8(s, third);
    avio_w8(s, fourth);
}