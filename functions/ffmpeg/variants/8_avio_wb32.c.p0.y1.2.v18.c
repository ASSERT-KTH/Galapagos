void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t *byte = (uint8_t *)&val + 3;
    for(int i = 0; i < 4; i++, byte--) {
        avio_w8(s, *byte);
    }
}