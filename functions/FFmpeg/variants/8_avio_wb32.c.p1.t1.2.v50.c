void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char chars[4];
    chars[0] = val >> 24;
    chars[1] = (uint8_t)(val >> 16);
    chars[2] = (uint8_t)(val >> 8 );
    chars[3] = (uint8_t) val;

    for(int i = 0; i < 4; i++) {
        avio_w8(s, chars[i]);
    }
}