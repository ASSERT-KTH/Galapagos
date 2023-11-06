Variant 1:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4){
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3])
      | ((uint32_t)(*xp)[2] << 8)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[0] << 24);
#else
  *zp = (*xp)[0]
      | ((*xp)[1] << 8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variant 2:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (!(4 <= *xn)) {
    return 0;
  }

#if (BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      + ((*xp)[1] << 8)
      + ((*xp)[2] << 16)
      + ((*xp)[3] << 24);
#else
  unsigned int conv;
  conv = ((*xp)[0] | ((*xp)[1] << 8) | ((*xp)[2] << 16) | ((*xp)[3] << 24));
  *zp = conv;
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}


Variant 3:

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof *zp) 
    return 0;

#if BTC_BIGENDIAN
  *zp = ((uint32_t)(*xp)[0] << 24)
      | ((uint32_t)(*xp)[1] << 16)
      | ((uint32_t)(*xp)[2] << 8)  
      | ((uint32_t)(*xp)[3]);
#else
  unsigned char *bzp = (unsigned char *)zp;
  bzp[0] = (*xp)[0];
  bzp[1] = (*xp)[1];
  bzp[2] = (*xp)[2];
  bzp[3] = (*xp)[3];
#endif
  
  *xp += sizeof *zp;
  *xn -= sizeof *zp;
 
  return 1;
}
