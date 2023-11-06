I

enum Endian { LITTLE, BIG };

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  enum Endian endianness = BIG;
#else
  enum Endian endianness = LITTLE;
#endif

  switch(endianness) {
    case LITTLE:
      memcpy(zp, *xp, sizeof(*zp));
      break;
      
    case BIG:
      *zp = ((uint32_t)(*xp)[0] <<  0)
          | ((uint32_t)(*xp)[1] <<  8)
          | ((uint32_t)(*xp)[2] << 16)
          | ((uint32_t)(*xp)[3] << 24);
      break;
  }

  *xp += 4;
  *xn -= 4;

  return 1;
}

II

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
 if (*xn < 4)
   return 0;

 uint32_t resultant = 0;

#if defined(BTC_BIGENDIAN)
 for(int i=0; i<4; ++i){
   resultant |= ((uint32_t)(*xp)[i] << (i * 8));
 }
#else
 memcpy(&resultant, *xp, sizeof(resultant));
#endif

 *zp = resultant;
 *xp += 4;
 *xn -= 4;

 return 1;
}
