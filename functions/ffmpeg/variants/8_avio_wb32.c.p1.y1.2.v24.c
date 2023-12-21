Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{    
    for(int i = 3; i >= 0; i--)
        avio_w8(s, (uint8_t)(val >> (8 * i)));
}


Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, ((val & 0xFF000000) >> 24));
    avio_w8(s, ((val & 0x00FF0000) >> 16));
    avio_w8(s, ((val & 0x0000FF00) >> 8));
    avio_w8(s,  (val & 0x000000FF));
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF000000;
    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, (val & mask) >> (8 * (3 - i)));
        mask >>= 8;
    }
}
