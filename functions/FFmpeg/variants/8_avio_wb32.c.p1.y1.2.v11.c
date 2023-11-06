Variant 1:


void avio_wb32(AVIOContext *s, unsigned int val)
{
   for (int i = 3; i >= 0; i--)
   {
       avio_w8(s, (uint8_t)(val >> (i*8)));
   }
}


Variant 2:


void avio_wb32(AVIOContext *s, unsigned int val)
{
   uint8_t bytes[4];
   for(int i=0; i<4; i++) {
       bytes[3-i] = (val >> (i*8));
   }
   for(int i=0; i<4; i++) {
       avio_w8(s, bytes[i]);
   }
}


Variant 3:


void avio_wb32(AVIOContext *s, unsigned int val)
{
   avio_w8(s, (uint8_t)(val >> 24 ));
   avio_w8(s, (uint8_t)((val >> 16) & 0xFF));
   avio_w8(s, (uint8_t)((val >> 8 ) & 0xFF));
   avio_w8(s, (uint8_t)(val & 0xFF));
}
