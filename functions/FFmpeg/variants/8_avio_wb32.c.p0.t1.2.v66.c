void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_one = val >> 24;
    unsigned char byte_two = (uint8_t)(val >> 16);
    unsigned char byte_three = (uint8_t)(val >> 8);
    unsigned char byte_four = (uint8_t) val;
    
    avio_w8(s, byte_one);
    avio_w8(s, byte_two);
    avio_w8(s, byte_three);
    avio_w8(s, byte_four);
}