uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;
  
#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0])
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#else
  *zp = *(*xp) | (*(*xp+1) << 8) | (*(*xp+2) << 16) | (*(*xp+3) << 24);
#endif

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}
The above program corresponds to a variant that slightly changes the behavior of the original function while maintaining its original functionality.
  - In the alternative little-endian section, rather direct memcpy, it has implemented the structure of explicitly field-wise copying like it is in the big-endian section.