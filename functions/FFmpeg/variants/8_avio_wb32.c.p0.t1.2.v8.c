void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int shift = 24; shift >= 0; shift -= 8) 
    {
        avio_w8(s, (uint8_t)(val >> shift));
    }  
}