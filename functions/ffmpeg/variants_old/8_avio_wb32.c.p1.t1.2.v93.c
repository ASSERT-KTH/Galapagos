void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int byte1, byte2, byte3, byte4;
    
    byte1 = (val & 0xFF000000) >> 24;
    byte2 = (val & 0x00FF0000) >> 16;
    byte3 = (val & 0x0000FF00) >> 8;
    byte4 = val & 0x000000FF;

    avio_w8(s, (uint8_t)byte1);
    avio_w8(s, (uint8_t)byte2);
    avio_w8(s, (uint8_t)byte3);
    avio_w8(s, (uint8_t)byte4);
}