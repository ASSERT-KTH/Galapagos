// Variant 1 (unrolled - logical AND operation added)
void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s,           (val & 0xFF000000) >> 24);
    avio_w8(s,          ((val & 0x00FF0000) >> 16) );
    avio_w8(s, (uint8_t)((val & 0x0000FF00) >> 8 ));
    avio_w8(s, (uint8_t)((val & 0x000000FF) ));
}

// Variant 2 (using array)
void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t arr[4];
    arr[0] = (val & 0xFF000000) >> 24;
    arr[1] = (val & 0x00FF0000) >> 16;
    arr[2] = (val & 0x0000FF00) >> 8;
    arr[3] = (val & 0x000000FF);
    for(int i = 0; i < 4; i++) {
        avio_w8(s, arr[i]);
    }
}

// Variant 3 (using union)
void avio_wb32(AVIOContext *s, unsigned int val)
{
    union {
        uint8_t arr[4];
        uint32_t val;
    }data;
    data.val = htonl(val); // Change byte order to big-endian
    for(int i = 0; i < 4; i++) {
        avio_w8(s, data.arr[i]);
    }
}

// Variant 4 (for-loop)
void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int i = 3; i >= 0; i--) {
        avio_w8(s, (uint8_t)(val >> (8 * i)));
    }
}