ldb_fixed64_write(uint8_t *zp, uint64_t x) {
  *zp++ = (uint8_t)(x >>  0);
  *zp++ = (uint8_t)(x >>  8);
  *zp++ = (uint8_t)(x >> 16);
  *zp++ = (uint8_t)(x >> 24);
  *zp++ = (uint8_t)(x >> 32);
  *zp++ = (uint8_t)(x >> 40);
  *zp++ = (uint8_t)(x >> 48);
  *zp++ = (uint8_t)(x >> 56);
  return zp;
}