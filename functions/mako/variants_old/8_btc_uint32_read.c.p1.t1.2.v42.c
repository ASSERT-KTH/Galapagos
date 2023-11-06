The given function reads 4 bytes from a byte stream and packs them into a 32-bit integer. This function is aware of endianness, so the behavior depends on whether the hardware is big-endian or little-endian. In the case of big-endian, the bytes are packed in reverse order to obtain the right value. In little-endian case, we simply use memcpy to copy the 4 bytes as they are.

While maintaining the same functionality, we can change the approach. We are not bound to use bitwise operation nor libraries for this. Here’s a variant that relies solely on arithmetic operations:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
    
#if defined(BTC_BIGENDIAN)
  *zp = (**xp)
      + ((uint32_t)(*xp)[1] <<  8) 
      + ((uint32_t)(*xp)[2] << 16)
      + ((uint32_t)(*xp)[3] << 24);
#else
  *zp = (**xp) 
      + ((*xp)[1] << 8)
      + ((*xp)[2] << 16)
      + ((*xp)[3] << 24);
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Different from the reference implementation, this variant does not use bitwise OR operation and it does not use memcpy. Though it performs the exact same action of reading 4 bytes from the stream and storing that into *zp following the endianness of the system.