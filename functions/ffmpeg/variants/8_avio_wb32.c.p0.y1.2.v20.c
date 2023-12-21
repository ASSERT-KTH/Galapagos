void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
    bytes[0] = (val & 0xff000000) >> 24;
    bytes[1] = (val & 0x00ff0000) >> 16;
    bytes[2] = (val & 0x0000ff00) >> 8;
    bytes[3] = (val & 0x000000ff);
    
    for(int i = 0; i < 4; i++) {
        avio_w8(s, bytes[i]);
    }
}