The code provided reads 4 bytes of data from the byte array pointed to by *xp and writes it as a 32 bit unsigned number in big-endian order into the memory pointed by zp. If there are at least 4 bytes of data in the byte stream pointed by *xp, it returns 1 otherwise returns 0. After reading the 32 bit number, it increments the memory location pointer by 4.

You are asking for a variant to this reference function which means maintain the same behavior in a slightly different way:

This variant implementation completes the same task but swaps the two sections, i.e., if the code is being ran in little endian system; it will have reversed memory allocation, so it is manually shifting each byte into the correct position. Towards that, memcpy in the else branch is removed and something similar to the upper part added instead:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  int data;
  if (*xn < 4) {
    return 0;
  }

#if defined(BTC_BIGENDIAN)
  data = ((uint32_t)(*xp)[0] << 24)
       | ((uint32_t)(*xp)[1] << 16)
       | ((uint32_t)(*xp)[2] << 8)
       | ((uint32_t)(*xp)[3]);
#else
  data = ((uint32_t)(*xp)[3] << 24)
       | ((uint32_t)(*xp)[2] << 16)
       | ((uint32_t)(*xp)[1] << 8)
       | ((uint32_t)(*xp)[0]);
#endif

  *zp = data;
  *xp += 4;
  *xn -= 4;

  return 1;
}


This variant essentially does the same thing as the previous one, but manually shifts and puts the data in the correct position. It is equivalent with the provided reference implementation, assuming it was intended to handle both types of endianness correctly.