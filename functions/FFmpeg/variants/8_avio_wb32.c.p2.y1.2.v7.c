void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int masks[4] = {0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF};
    int shifts[4] = {24, 16, 8, 0};

    for(int i = 0; i < 4; i++) {
        avio_w8(s, (uint8_t)((val & masks[i]) >> shifts[i]));
    }
}