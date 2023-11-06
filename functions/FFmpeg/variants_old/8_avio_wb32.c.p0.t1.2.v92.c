void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xff;
    avio_w8(s, (val >> 24) & mask);
    avio_w8(s, (val >> 16) & mask);
    avio_w8(s, (val >> 8) & mask);
    avio_w8(s,  val       & mask);
}