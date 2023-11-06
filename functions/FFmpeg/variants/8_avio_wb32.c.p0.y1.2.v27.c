void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t* bytes = (uint8_t*)&val;
    avio_w8(s, bytes[3]);
    avio_w8(s, bytes[2]);
    avio_w8(s, bytes[1]);
    avio_w8(s, bytes[0]);
}