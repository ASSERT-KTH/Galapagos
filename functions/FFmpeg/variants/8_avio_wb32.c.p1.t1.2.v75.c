void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte_values[4] = {
        (val & 0xFF000000) >> 24, 
        (val & 0x00FF0000) >> 16, 
        (val & 0x0000FF00) >> 8, 
        (val & 0x000000FF)
    };

    for(int i = 0; i < sizeof(byte_values)/sizeof(byte_values[0]); i++) {
        avio_w8(s, byte_values[i]);
    }
}