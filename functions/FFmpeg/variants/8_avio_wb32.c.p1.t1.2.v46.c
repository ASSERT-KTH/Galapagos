void avio_wb32(AVIOContext *s, unsigned int val) 
{
  unsigned char charArray[4];
  
  charArray[0] = val >> 24;
  charArray[1] = val >> 16;
  charArray[2] = val >> 8;
  charArray[3] = val;
    
  for(int i=0; i<4; i++) {
    avio_w8(s, charArray[i]);
  }
}