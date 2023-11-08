
void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  /* In case of big-endian, write 4 bytes into zp direction */
  *(uint32_t*)zp = x;
#else
  /* In case of little-endian, reverse the byte order via bit manipulations */
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >> 8);
  zp[3] = (uint8_t)(x);
#endif
}