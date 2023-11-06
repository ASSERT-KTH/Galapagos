Here's an alternative implementation. 


btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[3] <<  0)
       | ((uint32_t)xp[2] <<  8)
       | ((uint32_t)xp[1] << 16)
       | ((uint32_t)xp[0] << 24);
#else
  uint32_t z;
  z = *reinterpret_cast<const uint32_t *>(xp);
  return z;
#endif
}


Changes affected:

The bitwise operation for the case when `BTC_BIGENDIAN` is defined has been reversed compared to the original function.

And rather than using memcpy to copy the bytes from source buffer to the assigned space in memory, a c++ method to reinterpret the source pointer has been used.

It should be noted, though:
Both these variations do not change the functionality from the original function, they are alternative implementations to achieve more or less the same thing. The reinterpret_cast is less secure as compared with memcpy although faster which is why it might be preferred in conditions where speed is critical, however memcpy is the preferred method in most common scenarios. Its always best to understand your use case and requirements then choose accordingly.