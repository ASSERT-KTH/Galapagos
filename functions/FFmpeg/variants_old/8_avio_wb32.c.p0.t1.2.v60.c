void avio_wb32(AVIOContext *s, const unsigned int val)
{
    uint8_t upperByte = ((uint8_t)(val >> 24));
    uint8_t highMidByte = ((uint8_t)(val >> 16));
    uint8_t lowMidByte = ((uint8_t)(val >> 8));
    uint8_t lowerByte = ((uint8_t) val);

    avio_w8(s, upperByte);
    avio_w8(s, highMidByte);
    avio_w8(s, lowMidByte);
    avio_w8(s, lowerByte);
}