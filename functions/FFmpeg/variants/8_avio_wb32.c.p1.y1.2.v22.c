
void avio_wb32(AVIOContext *s, unsigned int val)
{   
    unsigned char data[4];

    data[0] = val >> 24;
    data[1] = (val >> 16) & 0xFF;
    data[2] = (val >> 8) & 0xFF;
    data[3] = val & 0xFF;

    for(int i = 0; i < 4; i++)
    {
        avio_w8(s, data[i]);
    }
}



void avio_wb32(AVIOContext *s, unsigned int val)
{
    for (int i = 3; i >= 0; i--)  
    {
        avio_w8(s, (val >> (i * 8)) & 0xFF);
    }    
}



void avio_wb32(AVIOContext *s, unsigned int val)
{
    int shift_val = 24;  
    for (int i = 0; i < 4; i++)  
    {
        avio_w8(s, val >> shift_val);
        shift_val -= 8;
    }
}
