void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int temp = val;
    avio_w8(s,           temp >> 24 );
    temp = val;
    avio_w8(s, (uint8_t)(temp >> 16));
    temp = val;
    avio_w8(s, (uint8_t)(temp >> 8 ));
    temp = val;
    avio_w8(s, (uint8_t) temp       );
}
