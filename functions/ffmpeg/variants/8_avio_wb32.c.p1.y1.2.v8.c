Variant 1:


void avio_wb32(AVIOContext *s, unsigned int val) {
    unsigned char bytes[4];
    bytes[0] = (uint8_t) (val >> 24);
    bytes[1] = (uint8_t) (val >> 16);
    bytes[2] = (uint8_t) (val >> 8 );
    bytes[3] = (uint8_t) val;

    for (int i = 0; i < 4; i++) {
        avio_w8(s, bytes[i]);
    }
}


Variant 2:


void avio_wb32(AVIOContext *s, unsigned int val) {
    for (int i = 3; i >= 0; --i) {
        avio_w8(s, (uint8_t)(val >> (8 * i)));
    }
}


Variant 3:


void avio_wb32(AVIOContext *s, unsigned int val) {
    unsigned int mask = 0xff << 24;
    for (int i = 0; i < 4; ++i) {
        avio_w8(s, (uint8_t)((val & mask) >> ((3-i) * 8)));
        mask >>= 8;
    }
}


Variant 4:


void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t bytes[4] = {
        (val >> 24) & 0xFF,
        (val >> 16) & 0xFF,
        (val >> 8 ) & 0xFF,
        val & 0xFF,
    };

    for (int i = 0; i < sizeof(bytes); ++i) {
        avio_w8(s, bytes[i]);
    }
}
