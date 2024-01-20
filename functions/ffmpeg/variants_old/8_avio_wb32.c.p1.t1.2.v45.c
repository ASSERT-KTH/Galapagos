void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte1 = (val & 0xFF000000) >> 24;
    uint8_t byte2 = (val & 0x00FF0000) >> 16;
    uint8_t byte3 = (val & 0x0000FF00) >> 8;
    uint8_t byte4 = (val & 0x000000FF);
    
    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}