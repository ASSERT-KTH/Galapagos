void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char vals[4];
    vals[0] = val >> 24;
    vals[1] = (uint8_t)(val >> 16);
    vals[2] = (uint8_t)(val >> 8);
    vals[3] = (uint8_t)val;

    for(int i=0; i<4; i++) {
        avio_w8(s, vals[i]);
    }
}