void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t values[4];
    values[0] = val >> 24;
    values[1] = (uint8_t)(val >> 16);
    values[2] = (uint8_t)(val >> 8);
    values[3] = (uint8_t) val; 

    avio_w8(s, values[0]);
    avio_w8(s, values[1]);
    avio_w8(s, values[2]);
    avio_w8(s, values[3]);
}