void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char fourthByte = (unsigned char)(val >> 24);
    unsigned char thirdByte  = (unsigned char)(val >> 16);
    unsigned char secondByte = (unsigned char)(val >> 8);
    unsigned char firstByte  = (unsigned char)val;

    avio_w8(s, fourthByte);
    avio_w8(s, thirdByte);
    avio_w8(s, secondByte);
    avio_w8(s, firstByte);
}