void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (unsigned char)(val / (1 << 24)));
    avio_w8(s, (unsigned char)((val / (1 << 16)) & 0xFF));
    avio_w8(s, (unsigned char)((val / (1 << 8))  & 0xFF));
    avio_w8(s, (unsigned char)(val       & 0xFF));
}