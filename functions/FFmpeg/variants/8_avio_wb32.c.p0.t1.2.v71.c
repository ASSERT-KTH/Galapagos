void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char first = (unsigned char)(val >> 24);
    unsigned char second = (unsigned char)(val >> 16);
    unsigned char third = (unsigned char)(val >> 8 );
    unsigned char fourth = (unsigned char) val;

    avio_w8(s, first);
    avio_w8(s, second);
    avio_w8(s, third);
    avio_w8(s, fourth);
}