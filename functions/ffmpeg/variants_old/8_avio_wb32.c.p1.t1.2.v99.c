void avio_wb32(AVIOContext *s, unsigned int val) {
    uint8_t byte[4];
    byte[0] = (uint8_t)(val >> 24);
    byte[1] = (uint8_t)(val >> 16);
    byte[2] = (uint8_t)(val >> 8 );
    byte[3] = (uint8_t) val;

    for(int i = 0; i < 4; i++) {
        avio_w8(s, byte[i]);
    }   
}