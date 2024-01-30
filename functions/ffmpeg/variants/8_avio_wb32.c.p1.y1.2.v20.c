Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    int shift_amt;
    for(shift_amt = 24; shift_amt >= 0; shift_amt -= 8)
    {
        avio_w8(s, (uint8_t)(val >> shift_amt));
    }
}


Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    unsigned char arr[4] = {(val >> 24), (val >> 16), (val >> 8), val};
    int i;
    for(i = 0; i < 4; i++)
    {
        avio_w8(s, arr[i]);
    }
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val) 
{
    uint8_t shift_amount[] = {24, 16, 8, 0};
    for(int i = 0; i < 4; i++){
        avio_w8(s, (uint8_t)(val >> shift_amount[i]));
    }
}


Variant 4:

void avio_wb32(AVIOContext *s, unsigned int val) {
    avio_w8(s, val>>24 & 0xFF);
    avio_w8(s, val>>16 & 0xFF);
    avio_w8(s, val>>8 & 0xFF);
    avio_w8(s, val & 0xFF);
}
