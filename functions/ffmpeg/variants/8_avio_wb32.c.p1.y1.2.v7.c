void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char byte4 = val>>24;
    unsigned char byte3 = val>>16;
    unsigned char byte2 = val>>8;
    unsigned char byte1 = val;;
    
    avio_w8(s, byte4);
    avio_w8(s, byte3);
    avio_w8(s, byte2);
    avio_w8(s, byte1);
}

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s,           (val & 0xFF000000) >> 24 );
    avio_w8(s, (uint8_t)((val & 0x00FF0000) >> 16));
    avio_w8(s, (uint8_t)((val & 0x0000FF00) >> 8 ));
    avio_w8(s, (uint8_t) (val & 0x000000FF)       );
}

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (uint8_t)(val / 0x1000000));
    avio_w8(s, (uint8_t)((val / 0x10000) & 0xFF));
    avio_w8(s, (uint8_t)((val / 0x100) & 0xFF));
    avio_w8(s, (uint8_t)(val & 0xFF));
}

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char arr[4];
    arr[0] = val >> 24;
    arr[1] = (val >> 16) & 0xFF;
    arr[2] = (val >> 8) & 0xFF;
    arr[3] = val & 0xFF;

    for (int i = 0; i < 4; i++) 
    {
        avio_w8(s, arr[i]);
    }
}