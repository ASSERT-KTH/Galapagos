void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byteMask = 0xFF; // mask to get each byte

    avio_w8(s, (byteMask & (val >> 24)));
    avio_w8(s, (byteMask & (val >> 16)));
    avio_w8(s, (byteMask & (val >> 8 )));
    avio_w8(s, (byteMask &  val       ));
}