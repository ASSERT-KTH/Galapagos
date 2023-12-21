void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t values[4];
    values[0] = val >> 24;
    values[1] = val >> 16;
    values[2] = val >> 8;
    values[3] = val;
    
    for (int i = 0; i < 4; i++)
    {
        avio_w8(s, values[i]);
    }
}

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for (int shift = 24; shift >= 0; shift -= 8)
    {
        avio_w8(s, (uint8_t)(val >> shift));
    }
}

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int masks[4] = { 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF };
    for (int i = 0; i < 4; i++){
        avio_w8(s, (val & masks[i]) >> (24 - i*8));
    }
}