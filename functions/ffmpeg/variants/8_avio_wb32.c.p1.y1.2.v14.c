
void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char b1 = val >> 24;
    unsigned char b2 = (val >> 16) & 0xFF;
    unsigned char b3 = (val >> 8) & 0xFF;
    unsigned char b4 = val & 0xFF;

    avio_w8(s, b1);
    avio_w8(s, b2);
    avio_wb8(s, b3);
    avio_wb8(s, b4);
}



void avio_wb32(AVIOContext* s, unsigned int val)
{
    for (unsigned i = 1; i <= 4; ++i)
    {
        avio_w8(s, (val >> (4 - i)*8) & 0xFF);
    }
}



void avio_wb32(AVIOContext* s, unsigned int val)
{
    uint8_t temp[4];
    temp[0] = val >> 24;
    temp[1] = (val >> 16) & 0xFF;
    temp[2] = (val >> 8) & 0xFF;
    temp[3] = val & 0xFF;
    
    for (int i = 0; i < 4; i++)
    {
        avio_w8(s, temp[i]);
    }
}
