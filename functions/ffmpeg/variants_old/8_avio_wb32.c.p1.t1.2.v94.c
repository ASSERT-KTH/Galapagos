unsigned char buffer[4];

void avio_wb32(AVIOContext *s, unsigned int val)
{
    buffer[0] = val >> 24;
    buffer[1] = (uint8_t)(val >> 16);
    buffer[2] = (uint8_t)(val >> 8);
    buffer[3] = (uint8_t)(val);

    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, buffer[i]);
    }
}