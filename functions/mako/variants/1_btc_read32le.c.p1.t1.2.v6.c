Here is a program variant:


uint32_t btc_read32le(const uint8_t *xp) {
#ifndef BTC_BIGENDIAN
  return ((uint32_t)xp[3] << 24)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[0] <<  0);
#else
  uint32_t z;
  z =  xp[3];
  z = (z<<8) | xp[2];
  z = (z<<8) | xp[1];
  z = (z<<8) | xp[0];
  return z;
#endif
}

This program reverses the byte order for Big Endian, aligning with functionality for little endian architecture, maintaining the function's original specifications and not introducing any auxiliary functions.