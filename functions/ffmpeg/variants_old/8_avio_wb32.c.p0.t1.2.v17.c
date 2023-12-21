void avio_wb32(AVIOContext *s, unsigned int val)
{
    // introduce local variable
    unsigned int shiftedVal = val;

    shiftedVal >>= 24; // shift by 24
    avio_w8(s, (uint8_t) shiftedVal );
    
    shiftedVal = val;
    shiftedVal >>= 16; // shift by 16 and mask
    avio_w8(s, (uint8_t)(shiftedVal & 0xFF)); 

    shiftedVal = val;
    shiftedVal >>= 8; // shift by 8 and mask
    avio_w8(s, (uint8_t)(shiftedVal & 0xFF));
    
    avio_w8(s, (uint8_t)(val & 0xFF));  //mask last 8 bits
}