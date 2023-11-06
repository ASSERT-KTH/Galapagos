1.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int shift; 
    for(shift = 24; shift != (~0u); shift -= 8) {
        avio_w8(s, (uint8_t)(val >> shift));
    }
}

2.

void avio_wb32(AVIOContext *s, unsigned int val)
{
   avio_w8(s, val >> 24);
   if ( val & 0x00FF0000 ) avio_w8(s, (uint8_t)(val >> 16));
   if ( val & 0x0000FF00 ) avio_w8(s, (uint8_t)(val >> 8));
   if ( val & 0x000000FF ) avio_w8(s, (uint8_t)val);
}

3.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    union {
        unsigned int val;
        unsigned char bytes[4];
    } valUnion; 
    
    valUnion.val = htonl(val);
    
    avio_w8(s, valUnion.bytes[0]);
    avio_w8(s, valUnion.bytes[1]);
    avio_w8(s, valUnion.bytes[2]);
    avio_w8(s, valUnion.bytes[3]);
}

4.

void avio_wb32(AVIOContext *s, unsigned int val)
{
    unsigned int mask = 0xFF000000;
    int i;
    for (i = 3; i >= 0; --i) {
        avio_w8(s, (uint8_t) ((val & (mask >> (i*8))) >> ((3-i)*8))];
    }
}
