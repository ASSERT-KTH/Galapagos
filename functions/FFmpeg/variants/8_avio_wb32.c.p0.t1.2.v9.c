void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int byteMask = 0x000000FF;

    avio_w8(s, (val & (byteMask << 24)) >> 24);
    avio_w8(s, (val & (byteMask << 16)) >> 16);
    avio_w8(s, (val & (byteMask << 8)) >> 8);
    avio_w8(s,  val &  byteMask);
}