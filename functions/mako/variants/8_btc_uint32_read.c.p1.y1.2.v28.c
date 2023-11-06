1. Variant with reversed conditions 

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4){

#if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif

    *xp += 4;
    *xn -= 4;

    return 1;
  }

  return 0;
}
    


2. Variant moving the return statement inside the if conditions 


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

#if defined(BTC_BIGENDIAN)
  if (*xn >= 4){
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);

    *xp += 4;
    *xn -= 4;

    return 1;
  }
#else
  if (*xn >= sizeof(*zp)){
    memcpy(zp, *xp, sizeof(*zp));

    *xp += sizeof(*zp);
    *xn -= sizeof(*zp);

    return 1;
  }
#endif

  return 0;
}


3. Variant with no macros but checks directly the system endianness 


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__){
      *zp = ((uint32_t)(*xp)[0] <<  0)
          | ((uint32_t)(*xp)[1] <<  8)
          | ((uint32_t)(*xp)[2] << 16)
          | ((uint32_t)(*xp)[3] << 24);
  } else {
      memcpy(zp, *xp, sizeof(*zp));
  }

  *xp += 4;
  *xn -= 4;

  return 1;
}


4. Variant reorganized operations 


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4) {
#if defined(BTC_BIGENDIAN)
          *zp = ((uint32_t)(*xp)[0])
              | ((uint32_t)(*xp)[1] <<  8)
              | ((uint32_t)(*xp)[2] << 16)
              | ((uint32_t)(*xp)[3] << 24);
#else
          memcpy(zp, *xp, sizeof(*zp));
#endif
          *xp = *xp + 4;
          *xn = *xn - 4;
          return 1;
  }
  return 0;
}


5. Variant changing the point of return


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) {
    return 0;
  }
#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[3] << 24)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[0]);
#else
  memcpy(zp, *xp, sizeof(*zp));
#endif

  *xp += 4;
  *xn -= 4;
  return 1;
}
