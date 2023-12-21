void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int firstByte = val >> 24;
    unsigned int secondByte = (uint8_t) (val >> 16);
    unsigned int thirdByte = (uint8_t) (val >> 8);
    unsigned int fourthByte = (uint8_t) val;
   
    avio_w8(s,           firstByte );
    avio_w8(s,           secondByte);
    avio_w8(s,           thirdByte );
    avio_w8(s,           fourthByte);
}