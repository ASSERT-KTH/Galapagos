void avio_wb32(AVIOContext *s, unsigned int val) 
{
    uint8_t bytes[4];
    
    // break the 32-bit unsigned int into an array of four 8-bit unsigned ints
    for (int i = 0; i < 4; ++i) 
    {
        bytes[i] = (uint8_t) (val >> (24 - (i * 8)));
    }

    // write each byte via avio_w8
    for (int i = 0; i < 4; ++i) 
    {
        avio_w8(s, bytes[i]);
    }
}