// Variant 1
void avio_wb32(AVIOContext *s, unsigned int val) {
    avio_w8(s, (val & 0xFF000000) >> 24);
    avio_w8(s, (val & 0x00FF0000) >> 16);
    avio_w8(s, (val & 0x0000FF00) >> 8);
    avio_w8(s, (val & 0x000000FF));
}

// Variant 2
void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t high_endian[4]; 
    high_endian[0] = (val >> 24 ) & 0xFF; 
    high_endian[1] = (val >> 16 ) & 0xFF;
    high_endian[2] = (val >> 8 ) & 0xFF; 
    high_endian[3] = val & 0xFF;  
    
    avio_w8(s, high_endian[0]);
    avio_w8(s, high_endian[1]);
    avio_w8(s, high_endian[2]);
    avio_w8(s, high_endian[3]);
}

// Variant 3 - using bitwise shifting
void avio_wb32(AVIOContext *s, unsigned int val) {
    for (int i = 3; i >= 0; i--) {
        avio_w8(s, (val >> (i*8)));
    }
}