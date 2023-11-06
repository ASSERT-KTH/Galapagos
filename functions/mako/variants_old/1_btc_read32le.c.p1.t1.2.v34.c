Here's a variation of your original function that changes its behaviour while still achieving the same functionality. Instead of using bitwise shifts directly, I used a for-loop to calculate them, allowing you to do additional operations if needed:


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t result = 0;
  for(int i=0; i<4; i++){
    result |= ((uint32_t)xp[i]<<(8*i));
  }
  return result;
#else
  uint32_t z;
  for(int i=0; i<sizeof(z); i++){
    ((uint8_t*)&z)[i]=xp[i];
  }
  return z;
#endif
}


In the big endian section of the code, a for loop is used instead of directly calculating the 8-bit shifts. This allows you to easily extend this code for larger sizes as well if needed.

In the little endian section of the code, the memcpy function is replaced with a for loop that does explicit byte by byte copying. More logic can be added inside this for loop if additional operations are needed.

Otherwise, the behavior remains the same as the original function.