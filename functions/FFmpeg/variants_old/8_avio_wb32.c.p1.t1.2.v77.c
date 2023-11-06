void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t bytes[4];
    bytes[0] = val >> 24;
    bytes[1] = (val >> 16) & 0xff;
    bytes[2] = (val >> 8) & 0xff;
    bytes[3] = val & 0xff;
 
    for(int i = 0; i < 4; ++i)
    {
        avio_w8(s, bytes[i]);
    }
}