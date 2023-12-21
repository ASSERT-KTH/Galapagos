void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_1, byte_2, byte_3, byte_4;

    byte_1 = (unsigned char)(val >> 24);
    byte_2 = (unsigned char)(val >> 16);
    byte_3 = (unsigned char)(val >> 8);
    byte_4 = (unsigned char) val;

    avio_w8(s, byte_1);
    avio_w8(s, byte_2);
    avio_w8(s, byte_3);
    avio_w8(s, byte_4);
}