void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int bytes[4];
     
    for(int i = 3; i >= 0; i--)
    {
        bytes[i] = (uint8_t)(val % 256);
        val /= 256;
    }
    
    for(int i = 0; i < 4; i++)
    {
   	    avio_w8(s, bytes[i]);
    }
}