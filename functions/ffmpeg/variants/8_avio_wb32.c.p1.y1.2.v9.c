1.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
    bytes[0] = val >> 24;
    bytes[1] = (uint8_t)val >> 16;
    bytes[2] = (uint8_t)val >> 8;
    bytes[3] = (uint8_t)val;     
      
    for (int i = 0; i < 4; i++)
       avio_w8(s, bytes[i]);
}

2.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    int i;
    for (i = 3; i >= 0; i--)
        avio_w8(s, (val >> (8*i)) & 0xFF );
}

3.

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
