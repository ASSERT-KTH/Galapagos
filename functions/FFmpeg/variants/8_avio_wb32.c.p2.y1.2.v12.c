void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shifted_val;
    uint8_t byte_val;

    shifted_val = val >> 24;
    avio_w8(s, shifted_val);

    shifted_val = val >> 16;
    byte_val = (uint8_t) shifted_val;
    avio_w8(s, byte_val);

    shifted_val = val >> 8;
    byte_val = (uint8_t) shifted_val;
    avio_w8(s, byte_val);

    byte_val = (uint8_t) val;
    avio_w8(s, byte_val);
}