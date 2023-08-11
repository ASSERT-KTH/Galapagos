uint32_t btc_read32le(const uint8_t *xp) {
#ifdef BTC_BIGENDIAN
  uint32_t reversed = (((uint32_t) xp[0]) | (((uint32_t) xp[1]) << 8) | (((uint32_t) xp[2]) << 16)
   | (((uint32_t)xp[3]) << 24));

  return ((reversed >> 24) & 0xff) | ((reversed >> 8) & 0xff00)
                | ((reversed << 8) & 0xff0000) | ((reversed << 24) & 0xff000000);
#else
  return xp[0] | xp[1]<<8 | xp[2]<<16 | xp[3]<<24;
#endif
}
