void avio_wb32(AVIOContext *s, unsigned int val) 
{
    unsigned int array[4];

    array[0] = val;
    array[1] = val >> 8;
    array[2] = val >> 16;
    array[3] = val >> 24;

    for (int i = 3; i >= 0; --i) 
    {
      avio_w8(s, (uint8_t) array[i]); 
    }
}