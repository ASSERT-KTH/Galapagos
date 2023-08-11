void avio_wb32(AVIOContext *s, unsigned int val)
{    
    uint8_t b3 = val >> 24;
    uint8_t b2 = (val >> 16) & 0xff; 
    uint8_t b1 = (val >> 8) & 0xff;
    uint8_t b0 = val & 0xff;
    
    avio_w8(s, b3);
    avio_w8(s, b2);
    avio_w8(s, b1);
    avio_w8(s, b0);
}