void avio_wb32(AVIOContext *s, unsigned int val) 
{
    uint32_t value = ((uint32_t) val);
    avio_w8 (s, (uint8_t) (value >> 24));
    avio_w8 (s, (uint8_t) ((value >> 16) & 0xFF));
    avio_w8 (s, (uint8_t) ((value >> 8) & 0xFF));
    avio_w8 (s, (uint8_t) (value & 0xFF));
}