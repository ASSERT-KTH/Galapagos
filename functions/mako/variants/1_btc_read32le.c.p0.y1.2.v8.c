The following function uses pointer cast and dereferencing instead of explicitly shifting and bitwise-ORing or using memcpy. If endianness isn't a concern, and it's certain that `xp` reliably points to at least a 4-byte sized block of memory, pointer representation can be used for direct conversion.

Same functionality is maintained here:

uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0])
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  return *(uint32_t*) xp;
#endif
}

Remember that depending on your system and compiler settings, this might possibly violate strict aliasing rules. It's not a universally applicable alternative, only valid in context where endianness doesn't matter and strict aliasing rules are not a concern. Be careful with such functionality replacement.