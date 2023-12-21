void avio_wb32(AVIOContext *s, unsigned int val) 
{
    uint8_t bytes[] = {val >> 24, (val >> 16) & 0xFF, (val >> 8) & 0xFF, val & 0xFF};
    for(int i = 0; i < sizeof(bytes); i++)
    {
        avio_w8(s, bytes[i]);
    }
}