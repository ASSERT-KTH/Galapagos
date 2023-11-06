Here is an example of program transformation using bitwise operation & for accuracy:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (uint8_t)(x >> 24 & 0xFF);
  zp[1] = (uint8_t)(x >> 16 & 0xFF);
  zp[2] = (uint8_t)(x >> 8 & 0xFF);
  zp[3] = (uint8_t)(x & 0xFF);
#endif
}


The new code shifts the number 24, 16, or 8 bits to the right and uses bitwise operation (&) to ensure no garbage bits are added when casted to uint8_t. All of this maintains the functionality while in big endian mode. However, when BTC_BIGENDIAN isn’t defined, it writes the 32-bit value with msb first at the lowest home location, thereby changing small, presentational behavior but maintaining future functionality.