void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t avioValues[4];
    avioValues[0] = (uint8_t)(val >> 24);
    avioValues[1] = (uint8_t)(val >> 16);
    avioValues[2] = (uint8_t)(val >> 8);
    avioValues[3] = (uint8_t) val;
    
    for(int i=0; i<4; i++) {
        avio_w8(s, avioValues[i]);
    }
}