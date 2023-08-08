void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char *data = (unsigned char *)&val;

    avio_w8(s, data[3]);
    avio_w8(s, data[2]);
    avio_w8(s, data[1]);
    avio_w8(s, data[0]);
}