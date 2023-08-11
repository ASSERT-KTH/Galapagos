void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char octet1 = val >> 24;
    unsigned char octet2 = (uint8_t)(val >> 16);
    unsigned char octet3 = (uint8_t)(val >> 8);
    unsigned char octet4 = (uint8_t) val;

    avio_w8(s, octet1);
    avio_w8(s, octet2);
    avio_w8(s, octet3);
    avio_w8(s, octet4);
}