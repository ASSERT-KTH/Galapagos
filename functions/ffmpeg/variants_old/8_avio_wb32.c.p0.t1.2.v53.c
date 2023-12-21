void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t b1, b2, b3, b4;
    b1 =          val >> 24;
    b2 = (uint8_t)(val >> 16);
    b3 = (uint8_t)(val >> 8 );
    b4 = (uint8_t) val;

    avio_w8(s, b1);
    avio_w8(s, b2);
    avio_w8(s, b3);
    avio_w8(s, b4);
}