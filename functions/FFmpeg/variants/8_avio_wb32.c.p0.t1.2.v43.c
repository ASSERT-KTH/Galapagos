void avio_wb32(AVIOContext *s, unsigned int val)
{
    val = htonl(val);
    avio_w8(s,           val & 0xff000000);
    avio_w8(s, (uint8_t)(val & 0x00ff0000));
    avio_w8(s, (uint8_t)(val & 0x0000ff00));
    avio_w8(s, (uint8_t)(val & 0x000000ff));
}