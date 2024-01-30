void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byteArr[4];
    for(int i=3; i>=0; --i, val >>= 8) 
    {
        byteArr[i] = (uint8_t)val;     
    }
    
    for(int i=0; i<4; ++i)
    {
        avio_w8(s, byteArr[i]);
    }
}