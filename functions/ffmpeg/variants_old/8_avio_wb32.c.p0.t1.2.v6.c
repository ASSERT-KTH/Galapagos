void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int first_bit = (val >> 24);
    unsigned int second_bit = (uint8_t)(val >> 16);
    unsigned int third_bit = (uint8_t)(val >> 8);
    unsigned int fourth_bit = (uint8_t) val;

    avio_w8(s, first_bit);
    avio_w8(s, second_bit);
    avio_w8(s, third_bit);
    avio_w8(s, fourth_bit);
}