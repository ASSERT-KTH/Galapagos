void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int byte_one, byte_two, byte_three, byte_four;

    byte_one = (val & 0xFF000000) >> 24;
    byte_two = (val & 0x00FF0000) >> 16;
    byte_three = (val & 0x0000FF00) >> 8;
    byte_four = (val & 0x000000FF);

    avio_w8(s, byte_one);
    avio_w8(s, byte_two);
    avio_w8(s, byte_three);
    avio_w8(s, byte_four);
}