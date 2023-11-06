Variant 1:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  uint32_t temp1, temp2, temp3, temp4;
  
  temp1 = (*xp)[0];
  temp1 = temp1 <<  0;
  
  temp2 = (*xp)[1];
  temp2 = temp2 <<  8;
  
  temp3 = (*xp)[2];
  temp3 = temp3 << 16;
  
  temp4 = (*xp)[3];
  temp4 = temp4 << 24;
  
  *zp = temp1 | temp2 | temp3 | temp4;
#else
  memcpy(zp, *xp, 4);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
`

Variant 2:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4) {
#if defined(BTC_BIGENDIAN)
    uint32_t read_value = ((uint32_t)(*xp)[3] << 24) | 
                          ((uint32_t)(*xp)[2] << 16) | 
                          ((uint32_t)(*xp)[1] <<  8) | 
                          ((uint32_t)(*xp)[0] <<  0);

    *zp = read_value;
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif

    *xp += 4;
    *xn -= 4;

    return 1;
  }

  return 0;
}


Variant 3:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp)) 
    return 0;

#if defined(BTC_BIGENDIAN)
  *((uint32_t *)xp) = (*zp) | ((*zp & 255) << 24) | ((*zp & 255) >> 24) | 
                      ((*zp & 255) << 8)  | ((*zp & 255) >> 8);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
