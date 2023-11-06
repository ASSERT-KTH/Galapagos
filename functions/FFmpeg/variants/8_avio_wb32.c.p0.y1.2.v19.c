void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char out[4];

    out[0] = (val >> 24) & 0xFF;
    out[1] = (val >> 16) & 0xFF;
    out[2] = (val >> 8) & 0xFF;
    out[3] = val & 0xFF;

    for(int i=0; i<4; i++) {
        avio_w8(s, out[i]);
    }
}