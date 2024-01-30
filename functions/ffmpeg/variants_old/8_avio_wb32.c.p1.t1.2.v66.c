void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shifted;
    for (int i = 3; i >= 0; --i)
    {
        shifted = val >> (8 * i);
        avio_w8(s, (uint8_t)shifted);
    }
}