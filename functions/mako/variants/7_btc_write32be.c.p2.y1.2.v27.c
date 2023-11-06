void btc_write32be(uint8_t *zp, uint32_t x) {
#ifdef BTC_BIGENDIAN
  x = ((x<<24)&0xFF000000u) | ((x<<8)&0x00FF0000u) | ((x>>8)&0x0000FF00u) | ((x>>24)&0x000000FFu);
#endif
  zp[0] = x / 16777216;
  zp[1] = x / 65536 % 256;
  zp[2] = x / 256 % 256;
  zp[3] = x % 256;
}