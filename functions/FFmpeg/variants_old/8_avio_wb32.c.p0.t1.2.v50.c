void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int i = 3; i >= 0; i--)
	    avio_w8(s, (uint8_t)(val >> (8*i)));
}