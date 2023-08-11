Here's a version of the same program, performed differently due to changes in the coding style and approach:


btc_uint32_write(uint8_t *zp, uint32_t x) {
#ifndef BTC_BIGENDIAN
  *zp = x & 0xff;
  *(zp + 1) = (x >> 8) & 0xff;
  *(zp + 2) = (x >> 16) & 0xff;
  *(zp + 3) = (x >> 24) & 0xff;
  return zp + sizeof(x);
#else
  x = (x>>24) | 
      ((x<<8) & 0x00ff0000) |
      ((x>>8) & 0x0000ff00) |
      (x<<24);
  memcpy(zp, &x, sizeof(x));
  return zp + 4;
#endif
}

Explanation:
In the switch with non-BigEndian, manual logic was implemented to get the split of `x` into an array of bytes.
For the BigEndian, bit manipulation was originally done on each byte using shifts and adds, I convert `x` to be from BigEndianness and then copy it, essentially doing the same thing as before,but assembling the whole on `x` before copying.