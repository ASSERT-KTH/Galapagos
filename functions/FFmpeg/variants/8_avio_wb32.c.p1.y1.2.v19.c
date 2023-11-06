Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t firstByte = val >> 24;
    uint8_t secondByte = (uint8_t)(val >> 16);
    uint8_t thirdByte = (uint8_t)(val >> 8);
    uint8_t fourthByte = (uint8_t)val;

    avio_w8(s, firstByte);
    avio_w8(s, secondByte);
    avio_w8(s, thirdByte);
    avio_w8(s, fourthByte);
}


Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val) {
    unsigned int shifts[] = {24, 16, 8, 0};
    for (short i = 0; i < 4; ++i) {
        avio_w8(s, (uint8_t)(val >> shifts[i]));
    }
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val) {
    for (short i = 0; i < sizeof(val); ++i) {
        avio_w8(s, (uint8_t)(val >> ((3 - i) * 8)));
    }
}


Variant 4:

void avio_wb32(AVIOContext *s, unsigned int val) {
    avio_w8(s, (val & 0xFF000000) >> 24 );
    avio_w8(s, (val & 0x00FF0000) >> 16);
    avio_w8(s, (val & 0x0000FF00) >> 8 );
    avio_w8(s, (val & 0x000000FF)      );
}

