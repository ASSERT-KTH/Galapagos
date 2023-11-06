Variant 1:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int num_of_shifts = 3;
  for(; num_of_shifts >= 0 ; num_of_shifts)-- {
      *zp++ = (uint8_t)(x >> (num_of_shifts * 8));
  }
  return zp;
#else
  zp[0] = x; 
  zp[1] = x>>8; 
  zp[2] = x>>16; 
  zp[3] = x>>24;
  return zp + 4;
#endif
}


Variant 2:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t* start = zp;
  uint8_t* end = zp + sizeof(x) - 1;
  while (start < end) {
      uint8_t temp = *start;
      *start = *end;
      *end = temp;

      start++;
      end--;
  }
  return zp + sizeof(x);
#else
  uint32_t* ptr = (uint32_t*)zp;
  *ptr = x;
  return zp + sizeof(x);
#endif
}


Variant 3:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *temp = zp;
  zp[3] = (uint8_t)(x>>0); 
  zp[2] = (uint8_t)(x>>8); 
  zp[1] = (uint8_t)(x>>16);
  zp[0] = (uint8_t)(x>>24);
  return temp + sizeof(x);
#else
  uint32_t* destination = (uint32_t*) zp;
  *destination = x;
  return zp + sizeof(x);
#endif
}
