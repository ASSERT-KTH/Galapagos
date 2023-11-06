1:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    avio_w8(s, val >> 24);
    avio_w8(s, (val >> 16) & 0xFF);
    avio_w8(s, (val >> 8)  & 0xFF);
    avio_w8(s, val & 0xFF);
}


2:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    unsigned int shift;
    for (shift = 24; shift <= 24 && shift >= 0; shift -= 8) 
    {
        avio_w8(s, (val >> shift) & 0xFF);
    }
}


3:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    uint8_t *ptr = (uint8_t *)&val + 3;
    for (int i = 0; i < 4; ++i) 
    {
        avio_w8(s, *ptr--);
    }
}


4:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    uint8_t bytes[4] = {val >> 24, val >> 16, val >> 8, val};
    for (int i = 0; i < 4; ++i)
    {
        avio_w8(s, bytes[i]);
    }
}
