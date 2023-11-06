Here is a variant of the function that uses casting to uint8_t* and arrow operator to directly manipulate the memory:


btc_uint32_write(uint8_t *zp, uint32_t x)
{
#if defined(BTC_BIGENDIAN)
  *zp++ = (uint8_t)((x >>  0) & 0x000000ff);
  *zp++ = (uint8_t)((x >>  8) & 0x000000ff);
  *zp++ = (uint8_t)((x >> 16) & 0x000000ff);
  *zp++ = (uint8_t)((x >> 24) & 0x000000ff);
  return zp - 4;
#else
  uint8_t* ptr = (uint8_t*) &x;
  *zp = *ptr++;
  *(zp + 1) = *ptr++;
  *(zp + 2) = *ptr++;
  *(zp + 3) = *ptr;
  return zp;
#endif
}

This implementation, while has the same functionality as the original one, uses a different approach particularly in the BTC_BIGENDIAN block. Rather than rearranging the bytes directly into the target pointer, it sequentially places each 8-bit part of the 32-bit input. In the else block, instead of using memcpy to copy the 32-bits value to the target pointer, it de-references a pointed address for each 8-bits of the 32-bits integer.