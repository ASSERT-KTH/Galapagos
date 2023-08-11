In this program variant, we do a quick trick by using union which offers an elegant solution to this problem while maintaining our function's signature.


#include <stdint.h>

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
  union {
    uint32_t number;
    uint8_t bytes[4];
  } picker0;
  
#if defined(BTC_BIGENDIAN)
  picker0.number = x; 
  *zp++ = picker0.bytes[3]; 
  *zp++ = picker0.bytes[2];
  *zp++ = picker0.bytes[1]; 
  *zp++ = picker0.bytes[0];
  
#else // little endian
  memcpy(zp, &x, sizeof(x));
#endif
  
  return zp;
}


Here, we use a union, `picker0`, to get a handle on the separate bytes of a given 32-bit integer. 

We access the separate bytes through the byte array, `bytes[]`, member of `picker0`, which makes the process of picking the bytes out trivial. 

Also remember that for standard 32-bit integers, the bytes are transferred from least significant (Little-Endian) to most significant (Big-Endian). Thus, byte 0 contains the least significant 8 bits, while byte 3 of the integer contains the most significant.

After assigning `picker0.number = x`, the memory of the number x can be interpreted as an array of four bytes `picker0.bytes[4]`.
 
Then just put each byte of our 32-bit integer into output array *zp, starting with the most significant: `picker0.bytes[3]`

Also note that in this solution memcpy is used to simply copy `unit32_t` x into `uint8_t` array zp when computer platform is Little-Endian.