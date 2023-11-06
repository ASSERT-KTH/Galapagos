Here is a variant of the given C code which gives the same functionality but achieves it in a slightly different way.


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  int i = 0;
  for(i=0; i<4; i++){
    zp[i] = (x>>(i*8));
  }
  return (zp + 4);
#else 
  uint32_t* val = (uint32_t*)zp;
  *val = x;
  return (zp + 4);
#endif
}


In the First case when big endian is defined I employed a for loop mechanism for shifting and storing the values into the allocated memory, while in the small endian fashion method rather than using memcpy, first we explicitly casted `zp` to a `uint32_t` pointer and then placed the `x` value into it, which should accomplish the same result done via memcpy. Nevertheless, this approach requires the system to allow combined reads and writes (i.e., it requires a certain amount of architectural judgement).