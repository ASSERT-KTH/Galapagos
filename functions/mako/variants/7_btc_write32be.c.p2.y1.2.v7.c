void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  zp[0] = x >> 24 & 0xFF;
  zp[1] = x >> 16 & 0xFF;
  zp[2] = x >> 8 & 0xFF;
  zp[3] = x & 0xFF;
#else
  uint32_t big_endian_x = ((x<<24) & 0xFF000000) |
                          ((x<<8) & 0x00FF0000) |
                          ((x>>8) & 0x0000FF00) |
                          ((x>>24) & 0x000000FF);
  memcpy(zp, &big_endian_x, sizeof(big_endian_x));
#endif
}