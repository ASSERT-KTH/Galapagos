void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char first_byte  = val >> 24;
    unsigned char second_byte = (uint8_t)(val >> 16);
    unsigned char third_byte  = (uint8_t)(val >> 8 );
    unsigned char fourth_byte = (uint8_t) val;

    avio_w8(s, first_byte );
    avio_w8(s, second_byte);
    avio_w8(s, third_byte );
    avio_w8(s, fourth_byte);
}