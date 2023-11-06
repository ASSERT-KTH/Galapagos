Variant 1:

`btc_uint32_write` function using bitwise AND operator


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x & 0xFF); 
  *zp++ = (uint8_t)((x >> 8) & 0xFF);
  *zp++ = (uint8_t)((x >> 16) & 0xFF);
  *zp++ = (uint8_t)((x >> 24) & 0xFF);
  return zp;
#else
  union { uint32_t x; uint8_t bytes[4]; } temp;
  temp.x = x;
  memcpy(zp, temp.bytes, sizeof(temp.bytes));
  return zp + 4;
#endif
}


Variant 2:

`btc_uint32_write` function using type casting


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)x; 
  *zp++ = (uint8_t)(x >> 8); 
  *zp++ = (uint8_t)(x >> 16); 
  *zp++ = (uint8_t)(x >> 24);
  return zp;
#else
  uint8_t* p = (uint8_t*)&x;
  for(int i = 0; i < sizeof(x); ++i) {
    *zp++ = *p++;
  }
  return zp;
#endif
}



Variant 3:

`btc_uint32_write` function using loop


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for (int i=0; i < 32; i+=8) {
    *zp++ = (x >> i);
  }
  return zp;
#else
  uint32_t* temp = &x;
  for (size_t i = 0; i < sizeof(*temp); i++) {
    *zp++ = ((uint8_t*)temp)[i];
  }
  return zp;
#endif
}
