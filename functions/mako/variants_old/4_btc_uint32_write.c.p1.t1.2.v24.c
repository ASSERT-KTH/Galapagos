void btc_uint32_write(uint8_t *zp, uint32_t x) {
    for(int i=0; i<sizeof(uint32_t); i++) {
#if defined(BTC_BIGENDIAN)
      *zp++ = (x >> (i*8)) & 0xFF;
#else
      zp[i] = (x >> (i*8)) & 0xFF;
#endif
    }
}