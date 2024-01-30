void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte1 = val >> 24;
    uint8_t byte2 = (val >> 16) & 0xFF;
    uint8_t byte3 = (val >> 8) & 0xFF;
    uint8_t byte4 = val & 0xFF;
    
    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}