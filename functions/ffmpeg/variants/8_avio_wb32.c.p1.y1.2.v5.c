Here are two variant transformations:

First variant:

Using Int-to-Pointer Casting, Changing order of subfunction calls, and using more explicit data type conversion for uint8_t

void avio_wb32(AVIOContext *s, unsigned int val) {
    avio_w8(s, (uint8_t)((val & 0xFF000000) >> 24));
    avio_w8(s, (uint8_t)((val & 0x00FF0000) >> 16));
    avio_w8(s, (uint8_t)((val & 0x0000FF00) >> 8));
    avio_w8(s, (uint8_t)(val & 0x000000FF ));
}


Second variant:

Using Int-to-Pointer Casting, Using Reverse Byte Order with bitwise, and using more explicit data type conversion for uint8_t

void avio_wb32(AVIOContext *s, unsigned int val) {
    avio_w8(s, (uint8_t)(val & 0x000000FF));
    avio_w8(s, (uint8_t)(val & 0x0000FF00) >> 8);
    avio_w8(s, (uint8_t)(val & 0x00FF0000) >> 16);
    avio_w8(s, (uint8_t)(val & 0xFF000000) >> 24);
}
