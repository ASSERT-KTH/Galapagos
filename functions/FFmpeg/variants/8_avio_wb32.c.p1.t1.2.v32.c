void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_array[4];
    for(int i = 0; i < 4; i++)
    {
        byte_array[i] = val >> ((3 - i)* 8); 
        avio_w8(s, byte_array[i]);
    }

}