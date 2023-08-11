btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t *ptr = (uint8_t*)&x;
  *zp++ = *ptr++;
  *zp++ = *ptr++;
  *zp++ = *ptr++;
  *zp = *ptr;
#else
  zp[3] = (uint8_t)(x & 255);
  x >>= 8;
  zp[2] = (uint8_t)(x & 255);
  x >>= 8;
  zp[1] = (uint8_t)(x & 255);
  x >>= 8;
  zp[0] = (uint8_t)(x & 255);
#endif
}