Here's a variant of the function which does the same thing as the original, only it flips the order of operations for both big-endian and little-endian architectures:


btc_uint32_write (uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *--zp = (x >> 24);
  *--zp = (x >> 16);
  *--zp = (x >>  8);
  *--zp = (x >>  0);
  return zp;
#else
  zp += 4;
  memcpy(zp, &x, sizeof(x));
  return zp - 4;
#endif
}

Please be cautious while using the post update version of this function. Generally in real programs other data is often closely allocated and we may overwrite it accidentally.