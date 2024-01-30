Option 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for (int i = 3; i >= 0; i--) {
        avio_w8(s, (uint8_t)(val >> (8 * i)));
    }
}

Option 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t bytes[4];
    bytes[0] = val >> 24;
    bytes[1] = (uint8_t)(val >> 16);
    bytes[2] = (uint8_t)(val >> 8);
    bytes[3] = (uint8_t)val;
    for (int i = 0; i < 4; i++) {
        avio_w8(s, bytes[i]);
    }
}

Option 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF000000;
    for (int i = 0; i < 4; i++, mask >>= 8) {
        avio_w8(s, (val & mask) >> (8 * (3 - i)));
    }
}

