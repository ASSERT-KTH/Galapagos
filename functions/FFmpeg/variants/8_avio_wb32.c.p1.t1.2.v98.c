void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
    for(int i = 3; i >= 0; --i)
    {
        bytes[i] = val & 0xFF;
        val >>= 8;
    }
    for(int i = 0; i < 4; ++i)
    {
        avio_w8(s, bytes[i]);
    }
}