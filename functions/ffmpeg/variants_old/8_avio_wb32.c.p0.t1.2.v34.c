void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (val & 0xFF000000) >> 24);
    avio_w8(s, (val & 0x00FF0000) >> 16);
    avio_w8(s, (val & 0x0000FF00) >> 8 );
    avio_w8(s, (val & 0x000000FF));
}