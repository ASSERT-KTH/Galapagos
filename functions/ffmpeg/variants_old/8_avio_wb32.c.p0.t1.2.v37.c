void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t byte1, byte2, byte3, byte4;

    byte1 = static_cast<uint8_t>(val >> 24);
    byte2 = static_cast<uint8_t>(val >> 16);
    byte3 = static_cast<uint8_t>(val >> 8);
    byte4 = static_cast<uint8_t>(val);

    avio_w8(s, byte1);
    avio_w8(s, byte2);
    avio_w8(s, byte3);
    avio_w8(s, byte4);
}