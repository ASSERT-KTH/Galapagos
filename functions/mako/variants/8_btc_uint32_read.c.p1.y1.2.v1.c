btc_uint32_read_v1(uint32_t *zp, const uint8_t **xp, size_t *xn){
  if (*xn <sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0])
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}

btc_uint32_read_v2(uint32_t* zp, const uint8_t** xp, size_t* xn) {
  if (*xn - sizeof(*zp) < 0) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)**xp)
      | ((uint32_t)*(*xp + 1) <<  8)
      | ((uint32_t)*(*xp + 2) << 16)
      | ((uint32_t)*(*xp + 3) << 24);
#else
  *zp = *((uint32_t*)*xp);
#endif

  *xp += 4;
  *xn -= 4; 

  return 1;
} 

btc_uint32_read_v3(uint32_t* zp, const uint8_t** xp, size_t* xn) {
  if(not (*xn >= 4)) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = 0;
  for (int i = 0; i < 4; ++i) {
      *zp |= (uint32_t)(*(*xp + i) << (i * 8));
  }
  
#else
  *zp = *((uint32_t*)*xp);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}