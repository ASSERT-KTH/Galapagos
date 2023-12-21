void avio_wb32(AVIOContext *s, unsigned int val) {
    unsigned int firstByte = val >> 24;
    unsigned int secondByte = (val & 0x00ff0000) >> 16;
    unsigned int thirdByte = (val & 0x0000ff00) >> 8;
    unsigned int fourthByte = val & 0x000000ff;
    
    avio_w8(s, firstByte);
    avio_w8(s, secondByte);
    avio_w8(s, thirdByte);
    avio_w8(s, fourthByte);
}
