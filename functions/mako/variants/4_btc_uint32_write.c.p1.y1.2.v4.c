1. A straightforward approach, keeping the endianness conditional but using explicit casting and assignment in the form of a packed structure:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)(x);
  *zp++ = (uint8_t)(x >> 8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
  return zp;
#else
  struct {uint32_t packed;} packedStruct;
  packedStruct.packed = x;
  memcpy(zp, &packedStruct, sizeof(packedStruct));
  return zp + sizeof(packedStruct);
#endif
}


2. Another approach skipping the memcpy and just filling the buffer manually in little endian order but in a more lengthy format:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >>  0);
  *zp++ = (x >>  8);
  *zp++ = (x >> 16);
  *zp++ = (x >> 24);
  return zp;
#else
  zp[0] = x;
  zp[1] = x >> 8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
  return zp + 4;
#endif
}


3. Conserving the original structure but adopting different binary shifts:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x & 0xFF000000 >> 24);
  *zp++ = (x & 0x00FF0000 >> 16);
  *zp++ = (x & 0x0000FF00 >> 8);
  *zp++ = (x & 0x000000FF);
  return zp;
#else
  memcpy(zp, &x, sizeof(x));
  return zp + sizeof(x);
#endif
}
