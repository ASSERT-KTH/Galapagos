void btc_write32be(uint8_t *zp, uint32_t x) {
    uint8_t *xp = (uint8_t*)&x;

    #if defined(BTC_BIGENDIAN)
      zp[0] = xp[0];
      zp[1] = xp[1];
      zp[2] = xp[2];
      zp[3] = xp[3];
    #else
      zp[0] = xp[3];
      zp[1] = xp[2];
      zp[2] = xp[1];
      zp[3] = xp[0];    
    #endif
}