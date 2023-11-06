btc_write32be(uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    uint8_t* xp = (uint8_t*)&x;
    for (int i = 0; i < sizeof(x); i++)
      {
        zp[i] = xp[i];
      }
#else
    for (int i = 0; i < 4; i++)
      {
        zp[i] = (x >> (24 - 8 * i)) & 0xFF;
      }
#endif
}