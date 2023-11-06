void avio_wb32(AVIOContext *s, unsigned int val)
{
    for (int i = 24; i >= 0; i -= 8)
    {
        avio_w8(s, (uint8_t)(val >> i));
    }
}