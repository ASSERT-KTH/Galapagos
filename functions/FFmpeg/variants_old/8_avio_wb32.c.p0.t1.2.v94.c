void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char parts[4];
    parts[0] = (unsigned char)(val >> 24);
    parts[1] = (unsigned char)((val & 0x00FF0000) >> 16 );
    parts[2] = (unsigned char)((val & 0x0000FF00) >> 8 );
    parts[3] = (unsigned char)(val & 0x000000FF);

    avio_w8(s, parts[0] );
    avio_w8(s, parts[1] );
    avio_w8(s, parts[2] );
    avio_w8(s, parts[3] );
}