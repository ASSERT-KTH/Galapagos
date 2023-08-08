void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  /* copying the memory a byte array */
  const uint8_t *xp = (const uint8_t *)&x;
  zp[3] = xp[0];
  zp[2] = xp[1];
  zp[1] = xp[2];
  zp[0] = xp[3];
#else
  /* writing the bytes manually reversed order */
  zp[3] = (uint8_t)(x & 0xFF);        
  zp[2] = (uint8_t)((x >> 8) & 0xFF);
  zp[1] = (uint8_t)((x >> 16) & 0xFF);
  zp[0] = (uint8_t)((x >> 24) & 0xFF);
#endif
}