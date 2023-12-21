void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t arr[4];
    
    for (int i = 3; i >= 0; i--) {
        arr[i] = (uint8_t)val;
        val = val >> 8;
    }
    
    for (int i = 0; i < 4; i++) {
        avio_w8(s, arr[i]);
    }
}