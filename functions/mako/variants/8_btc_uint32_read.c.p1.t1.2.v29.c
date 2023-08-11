Here's a variant where I made some small modifications while retaining the basic functionality of the function. The function ideally uses Big-Endian format but here, forLittle-Endian arrangement is implemented in the Else clause of Pre-processor directives.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
    
#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0] <<  0) 
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24); 
#else
  *zp = ((*xp)[0] << 24) 
      | ((*xp)[1] << 16)
      | ((*xp)[2] << 8)
      | ((*xp)[3] << 0); 
#endif

  *xp += 4;
  *xn -= 4;
  
  return 1;
}


It is important to note that there are several ways to interpret the Little Endian and Big Endian Models. The approach I used here was shifting in the opposite direction i.e., smaller places shifter towards the higher ones and the higher ones towards the lower ones.