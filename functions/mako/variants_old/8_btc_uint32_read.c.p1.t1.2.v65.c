Here's an alternative version of the original function. Despite looking different, it preserves the functionality of the original version now using a union to get the desired uint32 value. The endianess is now handled by reshuffling the bytes in the Little Endian part.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
  
  union {
    uint8_t bytes[4];
    uint32_t uint32;
  } value;

  memcpy(value.bytes, *xp, 4);

#if defined(BTC_BIGENDIAN)
  *zp = value.uint32;
#else
  // it is Little Endian so swap stored bytes in inverse order
  *zp = value.bytes[3] | value.bytes[2] << 8 | value.bytes[1] << 16 | value.bytes[0] << 24;
#endif
  
  *xp += 4;
  *xn -= 4;

  return 1;
}

         
In this rewrite byte reshuffling for Little Endian systems takes place with shifting and bitwise OR operations exactly like what was in BTC_BIGENDIAN case in the original function.
The BTC_BIGENDIAN now doesn't need to do anything additional except store the union value in result variable as the memcpy call already put the bytes in the correct order.