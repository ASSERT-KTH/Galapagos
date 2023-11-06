Here's a modified version of the original function with the same implementation, but slightly different code structure.


uint32_t btc_read32le(const uint8_t *xp) {
  uint32_t result = 0;
  #if defined(BTC_BIGENDIAN)
  result = 
     ((uint32_t)xp[0])
  |  ((uint32_t)xp[1] <<  8)
  |  ((uint32_t)xp[2] << 16)
  |  ((uint32_t)xp[3] << 24);
  #else
  memcpy(&result, xp, sizeof(result));
  #endif
  return result;
}


In this version, I create a `result` variable at the top of the function. For big-endian systems, I bitwise shift the elements of `xp` and `or` them together to construct the 32-bit value in little-endian way, which is then assigned to `result`.

On non big-endian systems (i.e., little-endian systems), I use memcpy to copy the `xp` directly into `result` because it represents exactly the value we want (since we're on a little-endian machine and the input is wanted to be interpreted in little endian).

Finally, I return `result` regardless of the architecture, ensuring the same output depending on the endian-ness of the system. I have maintained the original function's signature and functionality, while altering its structure and readability slightly.