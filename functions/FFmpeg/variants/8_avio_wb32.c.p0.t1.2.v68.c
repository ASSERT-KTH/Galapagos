void avio_wb32(AVIOContext *s, unsigned int val) 
{
    unsigned char byte1, byte2, byte3, byte4;
    byte1 = val >> 24;
    byte2 = val >> 16;
    byte3 = val >> 8;
    byte4 = val;
    
    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}