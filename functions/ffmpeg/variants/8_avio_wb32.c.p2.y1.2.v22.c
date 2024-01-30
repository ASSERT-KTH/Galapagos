void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF;
    for(int i = 3; i >= 0; --i)
    {
        avio_w8(s, (uint8_t) ((val & (mask << (8*i))) >> (8*i)));    
    }
}