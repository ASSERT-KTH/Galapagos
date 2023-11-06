1. Using ternary operator and eliminating preprocessor:

void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4) 
    return 0;

  unsigned int *endian_check = (unsigned int*)"\1\0\0\0";
  unsigned int is_big_endian = (*endian_check == 1) ? 0xFFFFFFFF: 0;

  is_big_endian ? (*zp = ((uint32_t)(*xp)[0] <<  0) 
                          | ((uint32_t)(*xp)[1] <<  8)
                          | ((uint32_t)(*xp)[2] << 16)
                          | ((uint32_t)(*xp)[3] << 24))
                         :
               memcpy(zp, *xp, sizeof(*zp));
  
  *xp += 4;
  *xn -= 4;
  
  return 1;
}
 
 2. Bitwise operators for logic:

void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (!(*xn & ~4)) 
    return 0;

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

3. Explicit casting instead of memcopy inLittle Endian section

void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  0)
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = *(uint32_t*)(*xp);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}

(Disclaimer: How you interpret the question can create a 'back and forth', I did not copy paste the portions so it should compile. Each of the implementations is point of consideration for inputs and functionality consistency validation)