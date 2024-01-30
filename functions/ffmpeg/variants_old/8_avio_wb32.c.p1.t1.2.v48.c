void avio_wb32(AVIOContext *s, unsigned int val)
{
    // Derived from splitting val into bytes.
    unsigned int first  = val & 0xFF000000;
    unsigned int second = val & 0x00FF0000;
    unsigned int third  = val & 0x0000FF00;
    unsigned int fourth = val & 0x000000FF;
    
    // Shifting and convert to uint8_t.
    avio_w8(s, first >> 24);
    avio_w8(s, (uint8_t)(second >> 16));
    avio_w8(s, (uint8_t)(third >> 8 ));
    avio_w8(s, (uint8_t)fourth );
}