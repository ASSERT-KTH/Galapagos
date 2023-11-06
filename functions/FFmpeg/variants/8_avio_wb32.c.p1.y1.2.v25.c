Version 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byteList[] = { 
        val >> 24,
        (uint8_t)(val >> 16),
        (uint8_t)(val >> 8),
        (uint8_t) val
    };
    
    for (int i = 0; i < 4; i++) {
        avio_w8(s, byteList[i]);
    }
}


Version 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for (int i = 24; i >= 0; i -= 8) {
        avio_w8(s, (uint8_t)(val >> i));
    }
}


Version 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (uint8_t)((val & 0xFF000000) >> 24));
    avio_w8(s, (uint8_t)((val & 0x00FF0000) >> 16));
    avio_w8(s, (uint8_t)((val & 0x0000FF00) >> 8));
    avio_w8(s, (uint8_t)(val & 0x000000FF));
}
