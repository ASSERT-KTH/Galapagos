void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_array[4];

    byte_array[0] = (val >> 24) & 0xFF;
    byte_array[1] = (val >> 16) & 0xFF;
    byte_array[2] = (val >>  8) & 0xFF;
    byte_array[3] = (val      ) & 0xFF;
    
    for(int i = 0; i < 4; i++) {
        avio_w8(s, byte_array[i]);
    }
}