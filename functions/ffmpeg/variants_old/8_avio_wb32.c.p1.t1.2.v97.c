void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char buf[4];
    buf[0] = val >> 24;
    buf[1] = val >> 16;
    buf[2] = val >> 8;
    buf[3] = val;

    for (int i = 0; i < 4; i++)
    {
        avio_w8(s, buf[i]);
    }
}