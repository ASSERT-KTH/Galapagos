int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  // if xn is less than 4, return 0
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)

  // read bytes from xp into zp
  *zp = ((uint32_t)(*xp)[3])        // last byte  
      | ((uint32_t)(*xp)[2] << 8)   // 3rd byte
      | ((uint32_t)(*xp)[1] << 16)  // 2nd byte
      | ((uint32_t)(*xp)[0] << 24); // 1st byte
#else
  // use the memcpy function to copy data from xp to zp
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}