void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
   
    bytes[0] = (unsigned char)(val >> 24 & 0xFF);
    bytes[1] = (unsigned char)(val >> 16 & 0xFF);
    bytes[2] = (unsigned char)(val >> 8  & 0xFF);
    bytes[3] = (unsigned char)(val       & 0xFF);
   
    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, bytes[i]);
    }
}