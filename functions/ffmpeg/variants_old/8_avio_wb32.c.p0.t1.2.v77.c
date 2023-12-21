void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t var[4];

    var[0] = val >> 24;
    var[1] = (uint8_t)(val >> 16);
    var[2] = (uint8_t)(val >> 8);
    var[3] = (uint8_t) val;

    for (int i = 0; i < 4; ++i)
    {
        avio_w8(s, var[i]);
    }
}