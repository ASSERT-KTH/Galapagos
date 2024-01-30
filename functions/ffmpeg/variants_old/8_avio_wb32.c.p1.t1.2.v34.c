void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byteArr[4];
    byteArr[0] = (unsigned char)(val >> 24);
    byteArr[1] = (unsigned char)(val >> 16);
    byteArr[2] = (unsigned char)(val >> 8 );
    byteArr[3] = (unsigned char) val;

    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, byteArr[i]);
    }
}