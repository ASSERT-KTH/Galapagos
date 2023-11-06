btc_write32be(uint8_t *zp, uint32_t x) {
  uint8_t* px = (uint8_t*) &x;
# if defined(BTC_BIGENDIAN)
  memcpy(zp, px, sizeof(x));
#else
  zp[3] = px[0]; 
  zp[2] = px[1]; 
  zp[1] = px[2];
  zp[0] = px[3]; 
# endif
}