void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int val1, val2, val3, val4;
    
    val1 = val >> 24;
    val2 = val >> 16;
    val3 = val >> 8;
    val4 = val;
    
    avio_w8(s,           val1);
    avio_w8(s, (uint8_t) val2);
    avio_w8(s, (uint8_t) val3);
    avio_w8(s, (uint8_t) val4);
}