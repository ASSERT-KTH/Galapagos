void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t values[4];
    values[0] = (uint8_t)(val >> 24);
    values[1] = (uint8_t)(val >> 16);
    values[2] = (uint8_t)(val >> 8 );
    values[3] = (uint8_t) val;

    for(int i = 0; i < 4; i++){
        avio_w8(s, values[i]);
    }
}