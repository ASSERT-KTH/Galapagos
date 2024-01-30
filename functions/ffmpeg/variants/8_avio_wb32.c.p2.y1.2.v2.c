void avio_wb32(AVIOContext *s, unsigned int val)
{   
    unsigned char array[4];
    array[0] = (unsigned char)(val >> 24);
    array[1] = (unsigned char)(val >> 16);
    array[2] = (unsigned char)(val >> 8 );
    array[3] = (unsigned char)(val);

    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, array[i]);
    }
}