void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte1, byte2, byte3, byte4;

    byte1 = (unsigned char) val >> 24;
    avio_w8(s, byte1);
    val -= ((unsigned int) byte1) << 24; 

    byte2 = (unsigned char) (val >> 16);
    avio_w8(s, byte2);
    val -= ((unsigned int) byte2) << 16;

    byte3 = (unsigned char) (val >> 8 );
    avio_w8(s, byte3);
    val -= ((unsigned int) byte3) << 8;

    byte4 = (unsigned char) val;
    avio_w8(s, byte4);
}