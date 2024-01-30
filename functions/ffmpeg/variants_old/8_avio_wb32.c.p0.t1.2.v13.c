void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shiftedVal;
    
    shiftedVal = val >> 24;
    avio_w8(s,           shiftedVal );
   
    shiftedVal = val >> 16;
    avio_w8(s, (uint8_t) shiftedVal);
  
    shiftedVal = val >> 8;
    avio_w8(s, (uint8_t) shiftedVal);

    shiftedVal = val;
    avio_w8(s, (uint8_t) shiftedVal );   
}