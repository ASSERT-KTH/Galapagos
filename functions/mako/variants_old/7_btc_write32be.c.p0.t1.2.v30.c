btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  uint32_t idx = 0;
  int shift_amount;
  
  for(shift_amount = 24; shift_amount >= 0; shift_amount -= 8) {
    zp[idx++] = (x >> shift_amount);
  }
#endif
}