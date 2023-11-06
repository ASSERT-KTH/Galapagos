void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char data[4];

    data[0] = (unsigned char) (val >> 24);
    data[1] = (unsigned char) (val >> 16);
    data[2] = (unsigned char) (val >> 8);
    data[3] = (unsigned char) val;

    for(int i = 0; i < 4; i++)
        avio_w8(s, (uint8_t)data[i]);
}