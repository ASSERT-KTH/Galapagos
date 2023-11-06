Shearing you the function variant:


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0])
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  return *((uint32_t*)(xp));
#endif
}

In this version, instead of copying the bytes from xp into z using memcpy, and then returning z, we instead let xp be treated as pointer to uint32_t (casting it) and immediately derreference the resulting pointer, returning its value. This, in essence, does the same as the original version: it reads 4 bytes from the position xp points to and returns them as uint32_t. This newer implementation, performs better, is smaller, but lacks a validity check as opposed to the actual memcpy. Performance gain is especially noticeable when reading large amounts of data byte-by-byte sequentially.