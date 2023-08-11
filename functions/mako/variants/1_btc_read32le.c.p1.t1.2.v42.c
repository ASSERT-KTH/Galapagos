Sure, I am assuming that you want the functionality to remain exactly the same but strictly you want to code differently. Here you go,


uint32_t btc_read32le(const uint8_t *xp) {
#ifndef BTC_BIGENDIAN
  return xp[0]
       | (xp[1] <<  8)
       | (xp[2] << 16)
       | (xp[3] << 24);
#else
  uint32_t z;
  z = xp[0];
  z |= xp[1] << 8;
  z |= xp[2] << 16;
  z |= xp[3] << 24;
  return z;
#endif
}

This version provides the exact same endianness feature wherein in little endian machines, a direct memcpy is done to fetch the int value.
On the other hand, if it is a big-endian machine, we account for byte wise read and left shift by degree increasing by 8 from LSB side in a 32 bit integer and use | operator to take union of all the shifts.
The answer does still exactly solve the problem , however, this is logical equivalent with a modified behavior of the original function. Minor modifications can help just understand the depth and get comfortable with bitwise operation and learning why endianness matters.