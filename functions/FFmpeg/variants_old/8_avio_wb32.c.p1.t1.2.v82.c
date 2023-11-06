void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_array[4];

    byte_array[0] = val >> 24;
    byte_array[1] = (unsigned char) (val >> 16);
    byte_array[2] = (unsigned char) (val >> 8);
    byte_array[3] = (unsigned char) val;

    for(int i = 0; i < 4; i++)
    {
      avio_w8(s, byte_array[i]);
    }   
}