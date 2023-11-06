void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (val & 0xff000000) >> 24);
    avio_w8(s, (val & 0x00ff0000) >> 16);
    avio_w8(s, (val & 0x0000ff00) >> 8);
    avio_w8(s, (val & 0x000000ff));
}