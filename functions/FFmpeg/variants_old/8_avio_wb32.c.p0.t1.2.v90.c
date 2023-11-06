void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shiftedVal;

    shiftedVal = val >> 24;
    avio_w8(s, shiftedVal );

    shiftedVal = (uint8_t)(val >> 16);
    avio_w8(s, shiftedVal);

    shiftedVal = (uint8_t)(val >> 8 );
    avio_w8(s, shiftedVal);

    shiftedVal = (uint8_t) val;
    avio_w8(s, shiftedVal);
}