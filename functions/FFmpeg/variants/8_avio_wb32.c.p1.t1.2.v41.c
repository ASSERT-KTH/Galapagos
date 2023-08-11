void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF;
    for(int shift = 24; shift >= 0; shift -= 8){
        avio_w8(s, (val & (mask << shift)) >> shift);
    }
}