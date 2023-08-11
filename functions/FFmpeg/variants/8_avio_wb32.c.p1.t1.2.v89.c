void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte[4];

    for (int i = 0; i < 4; i++)
    {
        byte[i] = val >> (24 - (i * 8));
        byte[i] = val;
    }

    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, byte[i]);
    }
}