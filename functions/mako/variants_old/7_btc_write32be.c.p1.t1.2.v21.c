Here is a single function code variant that maintains the same basic functionality as the original code:


btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t *)zp = x;
#else
  zp[0] = (uint8_t)((x & 0xFF000000) >> 24);
  zp[1] = (uint8_t)((x & 0x00FF0000) >> 16);
  zp[2] = (uint8_t)((x & 0x0000FF00) >> 8);
  zp[3] = (uint8_t)(x & 0x000000FF);
#endif
}


Here in the above code, a mask is applied to the integer before the bit shift, this is primarily to ignore the other bits we're not intending to get. Furthermore, we are case into `(uint8_t)` to ensures that the value is stored in a memory that fits a byte. The code under the `#if defined(BTC_BIGENDIAN)` dumps the integer directly into memory assuming that the machine is Big-endian hence does not need swapping.