btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  /* If the host machine is big endian, the higher order byte of the 
     number is stored in memory at the smallest address */

  zp[3] = (x >> 24) & 0xFF;
  zp[2] = (x >> 16) & 0xFF;
  zp[1] = (x >> 8) & 0xFF;
  zp[0] = x & 0xFF;
#else
  /* If the host machine is little endian, the lower order byte of the 
     number is stored in memory at the smallest address */

  x = ((x << 24) & 0xFF000000ul) | ((x << 8) & 0x00FF0000ul) | 
      ((x >> 8) & 0x0000FF00ul) | ((x >> 24) & 0x000000FFul);

  memcpy(zp, &x, sizeof(x));
#endif
}