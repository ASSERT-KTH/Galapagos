void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int newVal = val;
    avio_w8(s,           newVal >> 24 );
    newVal = val;
    avio_w8(s, (uint8_t)(newVal >> 16));
    newVal = val;
    avio_w8(s, (uint8_t)(newVal >> 8 ));
    newVal = val;
    avio_w8(s, (uint8_t) newVal );
}