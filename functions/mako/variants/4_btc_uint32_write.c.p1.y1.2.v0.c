Variant 1:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    *zp++ = (uint8_t)(x & 0xff);
    *zp++ = (uint8_t)((x >> 8) & 0xff);
    *zp++ = (uint8_t)((x >> 16) & 0xff);
    *zp++ = (uint8_t)(x >> 24);
    return zp;
#else
    uint8_t *t = (uint8_t*)&x;
    zp[0] = t[3];
    zp[1] = t[2];
    zp[2] = t[1];
    zp[3] = t[0];
    return zp + 4;
#endif
}

Variant 2:

btc_uint32_write(uint8_t *zp, uint32_t x) {
  for (int i = BTC_BIGENDIAN ? 0 : 3; BTC_BIGENDIAN ? (i < 4) : (i >= 0); BTC_BIGENDIAN ? i++ : --i){
    *zp++ = x >> (i * 8);
  }
  return zp;
}

Variant 3:

btc_uint32_write(uint8_t *zp, uint32_t x) {
#else
  union{ 
    uint32_t val; 
    uint8_t bytes[4]; 
  } data;

  data.val = BTC_BIGENDIAN? x : __builtin_bswap32(x);
  *zp++ = data.bytes[0];
  *zp++ = data.bytes[1];
  *zp++ = data.bytes[2];
  *zp++ = data.bytes[3];
   
  return zp;
}
