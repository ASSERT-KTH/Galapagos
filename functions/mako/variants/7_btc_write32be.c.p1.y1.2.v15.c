Version 1:

void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  zp[0] = x >> 24;
  zp[1] = x >> 16;
  zp[2] = x >> 8;
  zp[3] = x;
#else
  *zp = htonl(x);
#endif
}


Version 2:

void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  x = ((x<<24) & 0xFF000000u) | ((x<<8) & 0x00FF0000u) | ((x>>8) & 0x0000FF00u) | ((x>>24) & 0x000000FFu);
#endif
  memcpy(zp, &x, sizeof(uint32_t));
}


Version 3: 

void btc_write32be(uint8_t *zp, uint32_t x){
#ifdef BTC_BIGENDIAN
    –((uint32_t*)zp) = x;
#else
    *zp++ = x >> 24;
    *zp++ = x >> 16;
    *zp++ = x >> 8;
    *zp = x;
#endif
}
