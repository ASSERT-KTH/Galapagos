Variant 1:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    avio_w8(s,           (val & 0xFF000000) >> 24 );
    avio_w8(s, (uint8_t)((val & 0x00FF0000) >> 16));
    avio_w8(s, (uint8_t)((val & 0x0000FF00) >> 8 ));
    avio_w8(s, (uint8_t) (val & 0x000000FF)      );
}


Variant 2:

void avio_wb32(AVIOContext *s, unsigned int val)
{
     for(int shift=24; shift>=0; shift -= 8) {
        avio_w8(s, (uint8_t) (val >> shift ));
    }
}


Variant 3:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    for(int i=0; i<4; i++) {
	   avio_w8(s,(uint8_t)((val>>(24 - 8*i)) & 0xFF));
    }
}


Variant 4:

void avio_wb32(AVIOContext *s, unsigned int val)
{
    uint8_t bytes[4] = { val >> 24, 
                         val >> 16, 
                         val >> 8, 
                         val };

    for(int i=0; i< sizeof(bytes)/sizeof(uint8_t); i++)
        avio_w8(s, bytes[i]);
}

Note: The conversion to `uint8_t` truncates high value bytes. The bitwise and `& 0xFF` operation removes this issue by masking unaffected parts, keeping high bytes at zero.