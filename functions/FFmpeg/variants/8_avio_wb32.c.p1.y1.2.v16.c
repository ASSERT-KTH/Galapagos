// Variant 1: Using array
void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t vals[4];
    vals[0] = val >> 24;
    vals[1] = (uint8_t)(val >> 16);
    vals[2] = (uint8_t)(val >> 8);
    vals[3] = (uint8_t)val;
    for (int i = 0; i < 4; i++) {
        avio_w8(s, vals[i]);
    }
}

// Variant 2: Using the decrement operator
void avio_wb32(AVIOContext *s, unsigned int val) {
    int shift = 24;
    while (shift >= 0) {
        avio_w8(s, (uint8_t)(val >> shift));
        shift -= 8;
    }
}

// Variant 3: Using for loop
void avio_wb32(AVIOContext *s, unsigned int val) {
    for (int shift = 24; shift >= 0; shift -= 8) {
        avio_w8(s, (uint8_t)(val >> shift));
    }
}

// Variant 4: Using Manual shift logic
void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t fourthByte = val;
    uint8_t thirdByte = val >> 8;
    uint8_t secondByte = val >> 16;
    uint8_t firstByte = val >> 24;
    avio_w8(s, firstByte);
    avio_w8(s, secondByte);
    avio_w8(s, thirdByte);
    avio_w8(s, fourthByte);
}