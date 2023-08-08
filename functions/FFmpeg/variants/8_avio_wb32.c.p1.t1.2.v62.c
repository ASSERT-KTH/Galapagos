void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF;
    unsigned int byte;

    byte = (val >> 24) & mask;
    avio_w8(s, byte);

    byte = (val >> 16) & mask;
    avio_w8(s, (uint8_t)byte);

    byte = (val >> 8 ) & mask;
    avio_w8(s, (uint8_t)byte);

    byte = val & mask;
    avio_w8(s, (uint8_t)byte);
}