One possible variant of the same function could be:


void btc_write32be(uint8_t *zp, uint32_t x) {
#  if defined(BTC_BIGENDIAN)
    *zp++ = (x & 0x000000ff);
    *zp++ = (x & 0x0000ff00) >> 8;
    *zp++ = (x & 0x00ff0000) >> 16;
    *zp = (x & 0xff000000) >> 24;
#  else
    *zp++ = (x & 0xff000000) >> 24;
    *zp++ = (x & 0x00ff0000) >> 16;
    *zp++ = (x & 0x0000ff00) >> 8;
    *zp = (x & 0x000000ff);
#  endif
}


This alternate version of the function uses bitwise AND and bitwise shift operators differently but achieves the same result. The intention of the original program is preserved, only its appearance is affected. It rearranges the bits to reflect endianness.