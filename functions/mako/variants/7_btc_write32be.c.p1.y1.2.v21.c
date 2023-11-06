Variant 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  *(uint32_t*)zp = x;
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >>  8);
  zp[3] = (uint8_t)(x >>  0);
#endif
}


Variant 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
 for(int i=0; i< sizeof(x);i++){
    *zp = ((x>>(24-(i*8)))&0xFF);
    zp++;
 }
#else
 for(int i=0; i< sizeof(x);i++){
   *(zp+3-i)=((x>>(i*8))&0xff);
 }
#endif
}


Variant 3:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  unsigned int i;
  uint8_t *xp = (uint8_t*)&x;
  for(i = 0; i < sizeof(x); ++i) zp[i] = xp[i];
#else
  zp[0] = (x >> 24) & 0xff;
  zp[1] = (x >> 16) & 0xff;
  zp[2] = (x >>  8) & 0xff;
  zp[3] = (x >>  0) & 0xff;
#endif
}
