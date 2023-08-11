void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t parts[4] = {(val >> 24) & 0xFF, (val >> 16) & 0xFF, (val >> 8) & 0xFF, val & 0xFF};

    for (int i = 0; i < 4; ++i) {
        avio_w8(s, parts[i]);
    }
}