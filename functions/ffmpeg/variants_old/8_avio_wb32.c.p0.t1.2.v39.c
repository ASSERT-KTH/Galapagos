void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shifted_val;

    shifted_val = val >> 24;
    avio_w8(s, shifted_val);

    shifted_val = (uint8_t)(val >> 16);
    avio_w8(s, shifted_val);

    shifted_val = (uint8_t)(val >> 8);
    avio_w8(s, shifted_val);

    shifted_val = (uint8_t) val;
    avio_wb8(s, shifted_val);
}