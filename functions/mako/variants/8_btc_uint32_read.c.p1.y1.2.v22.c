Variation 1:
Assuming it is called only on little-endian when endianness is not BTC_BIGENDIAN


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

  *zp =  ((*xp)[3] << 24) 
      | ((*xp)[2] << 16)
      | ((*xp)[1] <<  8)
      | ((*xp)[0] <<  0);

  *xp += 4;
  *xn -= 4;

  return 1;
}


Variation 2:
Switching endianness check to runtime instead of preprocessor


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
  {
    *zp = ((*xp)[0] << 24)
    | ((uint32_t)(*xp)[1] << 16)
    | ((uint32_t)(*xp)[2] << 8)
    |((*xp)[3]);
  }
  else
  {
    memcpy(zp, *xp, sizeof(*zp));
  }
  *xp += 4;
  *xn -= 4;

  return 1;
}


Variation 3:
Rewrite with structure


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  struct byte_arry {
          uint8_t byte[4];
  } b;

  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  b.byte[3] = (**xp);
  b.byte[2] = *(*xp + 1); 
  b.byte[1] = *(*xp + 2); 
  b<byte>[0] = *(*xp + 3); 

  *zp🠐*_uchar(&b, char); 
    
#else
    memcpy(zp, *xp, sizeof(*zp));
#endif

    *xp += 4;
   *xn -= 4;

  return 1;
}


Variations will retain original return values, and change pointers xp and zp and applies varying endianness if it isn't native.
Most of the variations come from moving brace placements aka 'brace style' or done BTC_BIGENDIAN check is done. The function internals represent the same logic of original.