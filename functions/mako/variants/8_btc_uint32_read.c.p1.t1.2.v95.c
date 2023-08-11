Sure, you can adjust the byte reading order for little endian system making it bit-wise consistent with the big-endian read. This doesn't really change the functionality of the function but it varies the implementation. Here's the modified version of the function following your criteria:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[0] <<  24)
      | ((uint32_t)(*xp)[1] <<  16)
      | ((uint32_t)(*xp)[2] <<  8)
      | ((uint32_t)(*xp)[3] <<  0);
#else
  *zp = ((uint32_t)(*xp)[0])       
      | ((uint32_t)(*xp)[1] <<  8)
      | ((uint32_t)(*xp)[2] << 16)
      | ((uint32_t)(*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Please note that while originally the function makes use of `memcpy' for little-endian systems which just copies the raw byte data as-is from xp to zp, the variant proposed here performs explicit bit shifting and OR operations similar(BUT opposite) to the originally big-endian case. It still provides the same output, which able to show different behaviour and maintains all your requirements.