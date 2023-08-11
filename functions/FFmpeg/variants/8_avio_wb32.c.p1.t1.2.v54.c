void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
    bytes[0] = val >> 24;
    bytes[1] = (uint8_t)(val >> 16);
    bytes[2] = (uint8_t)(val >> 8);
    bytes[3] = (uint8_t) val;

    for(int i = 0; i < 4; i++) {
        avio_w8(s, bytes[i]);
    }
}