Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int val1, val2, val3, val4; 
    
    val1 = val >> 24;
    val2 = val >> 16 & 0xFF;
    val3 = val >> 8 & 0xFF;
    val4 = val & 0xFF;
    
    avio_w8(s, val1);
    avio_w8(s, val2);
    avio_w8(s, val3);
    avio_w8(s, val4);
}

  
Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];
    bytes[0] = (val >> 24) & 0xFF;
    bytes[1] = (val >> 16) & 0xFF;
    bytes[2] = (val >> 8) & 0xFF;
    bytes[3] = val & 0xFF;

    for(int i=0; i<4; i++) {
        avio_w8(s, bytes[i]);
    }
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int shift = 24; shift >= 0; shift -= 8) {
        avio_w8(s, (val >> shift) & 0xFF);
    }
}
 

Variant 4:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    int offset;
    
    for(offset = 24; offset >= 0; offset -= 8) {
        avio_w8(s, (val >> offset) & 0xFF);
    }
}
