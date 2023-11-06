void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int tmp = val;

    avio_w8(s, (uint8_t) (tmp >> 24));
    tmp <<= 8;
    avio_w8(s, (uint8_t) (tmp >> 24));
    tmp <<= 8;
    avio_w8(s, (uint8_t) (tmp >> 24));
    tmp <<= 8;
    avio_w8(s, (uint8_t) (tmp >> 24));
}