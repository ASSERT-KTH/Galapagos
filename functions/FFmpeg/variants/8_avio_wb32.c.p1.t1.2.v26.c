void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char values[4];
    
    values[0] = val >> 24;
    values[1] = (val >> 16) & 0xff;
    values[2] = (val >> 8 ) & 0xff;
    values[3] = val & 0xff;
    
    for(int i = 0; i < 4; i++) {
        avio_w8(s, values[i]);
    }
}