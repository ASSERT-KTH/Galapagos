Here is one way to also meet the requirements:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN 
  *zp++ = (uint8_t) (x & 0xFF);
  *zp++ = (uint8_t) ((x >> 8) & 0xFF);
  *zp++ = (uint8_t) ((x >> 16) & 0xFF);
  *zp++ = (uint8_t) ((x >> 24) & 0xFF);
#else
  x = ((x & 0xFF) << 24) | ((x & 0xFF00) << 8) | ((x & 0xFF0000) >> 8) | ((x & 0xFF000000) >> 24);
  memcpy(zp, &x, sizeof(x));
#endif
}


This version overall maintains the intended big and little-endian writing functionality by effectively handling both endianness situations but handles them using a slightly different approach.

Note: Given how close the two codes ended up looking, it seems that they would have identical results - carefully note that don't they, due to the differing order of steps, which does indeed mean this differs in processing steps.