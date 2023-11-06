1. Direct Bitmasking

There are other ways to extract particularly byte from a uint32_t using the bitwise AND operator with a bitmask. 

This variant also features a slightly more expressive scheme where each operation is within the context of a series of parentheses for clarity.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0x000000ff) >>  0;
  *zp++ = (x & 0x0000ff00) >>  8;
  *zp++ = (x & 0x00ff0000) >> 16;
  *zp++ = (x & 0xff000000) >> 24;
#else 
  memcpy(zp, &x, sizeof(x));
  return zp + sizeof(x);  
#endif
  return zp;
}


2. Less Associative Array Access

We can also pass over the array less by computing all the computations first. This leads to fewer steps taken in modifying the memory.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t a = (x & 0x000000ff);
  uint8_t b = (x & 0x0000ff00) >> 8;
  uint8_t c = (x & 0x00ff0000) >> 16;
  uint8_t d = (x & 0xff000000) >> 24;

  *zp++ = a;
  *zp++ = b;
  *zp++ = c;
  *zp++ = d;
#else 
  memcpy(zp, &x, sizeof(x));
  return zp + sizeof(x);
#endif 
  return zp;
}


3. Using Unions

Another way especially for little-endian is the extraction of byte data using a union representation of the uint32 value.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0);
  *zp++ = (x >>  8);
  *zp++ = (x >> 16);
  *zp++ = (x >>  24);
#else 
  union {
    uint32_t u32;
    uint8_t arr[sizeof(uint32_t)];
  } tmp;

  tmp.u32 = x;
  memcpy(zp, tmp.arr, sizeof(uint32_t));
  
  return zp + sizeof(uint32_t);
#endif
  return zp;
}
