btc_write32be(uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(size_t i = 0; i < sizeof(x); ++i)
    zp[i] = ((uint8_t*)&x)[i];
#else
  uint8_t* xp = (uint8_t*)&x;
  zp[0] = *(xp+3);
  zp[1] = *(xp+2);
  zp[2] = *(xp+1);
  zp[3] = *xp;
#endif
}