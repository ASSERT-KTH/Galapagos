void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF;
    int shift = 24;
    for(int i = 0; i < 4; i++) 
    {
        avio_w8(s, (uint8_t)((val & (mask << shift)) >> shift));
        shift -= 8;
    }
}