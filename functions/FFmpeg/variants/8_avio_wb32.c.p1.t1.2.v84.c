void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
    bytes[0] = (val >> 24) & 0xFF;
    bytes[1] = (val >> 16) & 0xFF;
    bytes[2] = (val >> 8) & 0xFF;
    bytes[3] = val & 0xFF;

    for(int i = 0; i < 4 ; ++i)
        avio_w8(s, bytes[i]);
}