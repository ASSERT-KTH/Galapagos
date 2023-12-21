1. Subsequent Use of Effect Assignments

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (val >> 24 ));
    avio_w8(s, ((val = val << 8) >> 24));
    avio_w8(s, ((val = val << 8) >> 24));
    avio_w8(s, ((val = val << 8) >> 24));
}

2. Bit Shifting Operations Refactored

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s, (val & (0xF << 24)) >> 24);
    avio_w8(s, (val & (0xF << 16)) >> 16);
    avio_w8(s, (val & (0xF << 8 )) >> 8 );
    avio_w8(s, (val &  0xF));
}

3. To Selectively take bytes and create a casual program flow

void avio_wb32(AVIOContext *s, unsigned int val)
{
    int i;
    for(i = 24; i >= 0; i -= 8 ) {
        avio_w8(s, ((val & (0xf << i) ) >> i));
    }
}

4. Subsequent Transformations through Shift and Hand-off Assignment  

void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t vals[4] = {(val >> 24), (val >> 16), (val >> 8), val};
    avio_w8(s, vals[0]);
    avio_w8(s, vals[1]);
    avio_w8(s, vals[2]);
    avio_w8(s, vals[3]);
}
   
5. Consecutive Write Function Calls Through Ternary Conditional Expression

void avio_wb32(AVIOContext *s, unsigned int val)
{
    (void)(( avio_w8(s, (val >> 24)) || avio_w8(s, (val >> 16)) || avio_w8(s, (val >> 8)) || avio_w8(s, (val))) ? 0 : 0); 
}
