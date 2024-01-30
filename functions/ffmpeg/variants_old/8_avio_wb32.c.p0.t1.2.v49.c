void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int temp_val = val;
    avio_w8(s,           temp_val & 0xFF000000 >> 24);
    temp_val <<= 8;
    avio_w8(s, (uint8_t)(temp_val & 0xFF000000 >> 24));
    temp_val <<= 8;
    avio_w8(s, (uint8_t)(temp_val & 0xFF000000 >> 24));
    temp_val <<= 8;
    avio_w8(s, (uint8_t)(temp_val & 0xFF000000 >> 24));
}