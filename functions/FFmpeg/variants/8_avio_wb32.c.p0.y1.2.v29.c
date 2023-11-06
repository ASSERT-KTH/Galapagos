void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int i = sizeof(val)-1; i >= 0; --i) {
        uint8_t byte = (uint8_t) (val >> (8*i));
        avio_w8(s, byte);
    }
}