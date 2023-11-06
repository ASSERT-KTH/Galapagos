uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if(*xn < 4)
    return 0;
   
  uint8_t *byte_array = (uint8_t *) zp;

#if defined(BTC_BIGENDIAN)
  byte_array[0] = (*xp)[0];
  byte_array[1] = (*xp)[1];
  byte_array[2] = (*xp)[2];
  byte_array[3] = (*xp)[3];
#else
  byte_array[0] = (*xp)[3];
  byte_array[1] = (*xp)[2];
  byte_array[2] = (*xp)[1];
  byte_array[3] = (*xp)[0];
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}