void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shifted;
    uint8_t byte;

    shifted = val >> 24;
    byte = (uint8_t) shifted;
    avio_w8(s, byte);

    shifted = val >> 16;
    byte = (uint8_t) shifted;
    avio_w8(s, byte);

    shifted = val >> 8;
    byte = (uint8_t) shifted;
    avio_w8(s, byte);

    byte = (uint8_t) val;
    avio_w8(s, byte);
}