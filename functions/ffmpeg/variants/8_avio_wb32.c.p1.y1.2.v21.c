Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{
   unsigned char temp[4];
   temp[0] = (unsigned char) (val >> 24);
   temp[1] = (unsigned char) (val >> 16);
   temp[2] = (unsigned char) (val >> 8);
   temp[3] = (unsigned char) val;   

    for (int i=0; i<4; i++) 
    {
        avio_w8(s, temp[i]);
    }
}


Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
   unsigned char *temp = (unsigned char *)&val;
   for(int i = 0; i < 4; ++i)
   {
        avio_w8(s, *(temp+3-i));
   }
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int shift = 24; shift >= 0; shift -= 8)
    {
        avio_w8(s, val >> shift);
    }
}
