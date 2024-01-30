void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char b[4];

    b[0] = (unsigned char)(val >> 24);
    b[1] = (unsigned char)(val >> 16);
    b[2] = (unsigned char)(val >> 8);
    b[3] = (unsigned char)val;

    for (int i = 0; i < 4; i++) {
        avio_w8(s, b[i]);
    }
}