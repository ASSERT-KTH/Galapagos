
void btc_write32be(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  x = htonl(x); 
#endif
  memcpy(zp, &x, sizeof(x));
}
