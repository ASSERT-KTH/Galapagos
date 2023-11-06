
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >>  0);
  zp[1] = (x >>  8);
  zp[2] = (x >> 16);
  zp[3] = (x >> 24);
#else
  uint8_t tmp[sizeof(x)];
  memcpy(tmp, &x, sizeof(x));
  for (size_t i = 0; i < sizeof(x); ++i) {
      zp[i] = tmp[i];
  }
#endif
}

This variant of the function places the transformed bytes at the specific slots of your data array directly when the number is processed in big endian order. In the little endian version, procedure copies the bytes to a temporary array that they transferred from to the correct slot after.