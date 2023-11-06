You can rearrange the bitwise operations and still maintain the same functionality. 

Here is the alternative code:

btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x >> 24) & 0xFF;
  zp[1] = (x >> 16) & 0xFF;
  zp[2] = (x >>  8) & 0xFF;
  zp[3] = x & 0xFF;
#endif
}


The change here involves trailing the bitwise operation with the binary digital & operator, aiming to extract the byte we shift to. It is a common practice when implementing this kind of function. Although it's an unnecessary operation in this context since the higher significant bytes just disappear when shifting due to zp[i] being an 8-bit data type, it might illustrate better what is happening for people who are reading the code.