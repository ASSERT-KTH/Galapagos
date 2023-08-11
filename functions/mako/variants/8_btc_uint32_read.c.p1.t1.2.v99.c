Here is the variant of the provided function. The functionality is the same as original, but the internal implementation is slightly different.





btc_uint32_read(uint32_t* zp, const uint8_t** xp, size_t* xn) {
  if(*xn < 4) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  for (size_t i = 0; i < 4; ++i) {
    *zp |= (uint32_t)((*xp)[i] << (i * 8));
  }
#else
  uint8_t* tp=*xp;
  for(size_t ind=0;ind<4;++ind)
  {
    *zp += *(tp+ind) << (im*8);
  }
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}
