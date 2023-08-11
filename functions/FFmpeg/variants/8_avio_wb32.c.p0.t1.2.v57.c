void avio_wb32(AVIOContext *s, unsigned int val)
{
    val = (val >> 16) | (val << 16);
    avio_w8(s,           val >> 24 );
    avio_w8(s,           val >> 16 );
    avio_w8(s, (uint8_t)(val >> 8 ));
    avio_w8(s, (uint8_t) val       );
    val = (val >> 16) | (val << 16);
}