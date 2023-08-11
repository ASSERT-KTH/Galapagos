void avio_wb32(AVIOContext *s, unsigned int val)
{   
    unsigned int first  = val >> 24;
    uint8_t second = (uint8_t)(val >> 16);
    uint8_t third = (uint8_t)(val >>  8);
    uint8_t fourth = (uint8_t) val;
    
    avio_w8(s, first);
    avio_w8(s, second);
    avio_w8(s, third);
    avio_w8(s, fourth);
}