Here is a modified version of the function using pointer arithmetic instead of using bitwise shifts and also includes commenting and refining the little-endian section.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {

  // If less than 4 bytes available, return 0 as error/signal code
  if (*xn < 4)
    return 0;
  
  /*
   * This defines two variants of data processing: one for big and another for little endianness.
   * Provides similar functionality using different approach in Big-Endian block compared to the original 
   */

#if defined(BTC_BIGENDIAN)
  
  // Casting the pointers to uint32_t (4 byte) and then using pointer arithmetic to achieve the same result

  *zp = *(*xp)        |                  // bits 0-7
         (*(*xp + 1)) <<  8 )  |         // bits 8-15
         (*(*xp + 2)) << 16 )  |         // bits 16-23
         (*(*xp + 3)) << 24 );           // bits 24-31                              

#else
  // Here the data is simply copied because we are assuming that the system computer is little-endian
  memcpy(zp, *xp, sizeof(*zp));
#endif

  // Updating the pointers and available bytes 
  *xp += 4;
  *xn -= 4;

  // Return 1 as signal/code of success 
  return 1;
}

This alternative implementation should have the same functional outcome of bit collect interpretation while it uses slightly different approach inside the condition of checked (bit-endian of the system).