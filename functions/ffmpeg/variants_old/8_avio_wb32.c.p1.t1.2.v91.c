void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned char bytes[4];

    // Populate array with bytes of val, starting from highest
    for (int idx = 0; idx < 4; idx++) {
        bytes[idx] = val >> ((3 - idx) * 8);
    }

    // Write bytes to AVIOContext
    for (int idx = 0; idx < 4; idx++) {
        avio_w8(s, bytes[idx]);
    }
}