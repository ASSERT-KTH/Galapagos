void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char ch[4];
    
    ch[0] =           val >> 24;
    ch[1] = (uint8_t)(val >> 16);
    ch[2] = (uint8_t)(val >> 8);
    ch[3] = (uint8_t) val;

    for (int i = 0; i < 4; i++) {
        avio_w8(s, ch[i]);
    }
}