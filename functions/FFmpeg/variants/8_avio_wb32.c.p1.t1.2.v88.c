Here is an alternative program variant. It maintains the original functionality by writing the provided 32-bit unsigned integer into the AVIOContext as a 4 byte big-endian number.

void avio_wb32(AVIOContext *s, unsigned int val) {
    for(int i = 24; i >= 0; i -= 8){
        avio_w8(s, (uint8_t)(val >> i));
    }
}