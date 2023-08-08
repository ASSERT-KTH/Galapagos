void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (unsigned int)(val >> 24) & 0xFF);
    avio_w8(s, (unsigned int)(val >> 16) & 0xFF);
    avio_w8(s, (unsigned int)(val >> 8 ) & 0xFF);
    avio_w8(s, (unsigned int) val        & 0xFF);
}