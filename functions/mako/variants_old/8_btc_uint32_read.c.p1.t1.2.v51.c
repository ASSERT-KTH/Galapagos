uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(uint32_t))
    return 0;

#if defined(BTC_BIGENDIAN)
  const uint8_t* temp = *xp;

  *zp = ((uint32_t)temp[0] <<  0) |
        ((uint32_t)temp[1] <<  8) |
        ((uint32_t)temp[2] << 16) |
        ((uint32_t)temp[3] << 24);
  temp += 4;
#else
  const uint8_t* temp = *xp;
  for(int i=0; i< sizeof(*zp); i++){
      *zp |= temp[i] << (i * 8);
  }
  temp += sizeof(*zp);
#endif

  *xp = temp;
  *xn -= sizeof(*zp);

  return 1;
}