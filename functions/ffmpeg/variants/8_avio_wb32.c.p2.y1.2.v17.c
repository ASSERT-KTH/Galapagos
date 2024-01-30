void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int byte_mask = 0xFF; // Bitmask for extracting 8 bit value in 32 bit int 

    // Write the most significant byte
    avio_w8(s, (val >> 24) & byte_mask);

    // Write the second most significant byte
    avio_w8(s, (val >> 16) & byte_mask);

    // Write the third most significant byte
    avio_w8(s, (val >> 8) & byte_mask);

    // Write the least significant byte
    avio_w8(s, val & byte_mask);
}