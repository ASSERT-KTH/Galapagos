void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_array[4];
    byte_array[0] = (uint8_t)(val >> 24);
    byte_array[1]=(uint8_t)(val >> 16);
    byte_array[2]=(uint8_t)(val >> 8);
    byte_array[3] = (uint8_t) val;

    for(int i = 0; i < 4; i++) {
        avio_w8(s, byte_array[i]);
    }
}