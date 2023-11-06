Here's a variant of the function that retains its original behavior without needing preprocessor macros to differentiate between different system endianness. Instead, it calculates the endianness at runtime.


#include <stdint.h>
#include <string.h>

int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
  
  // Creating a value and pointing to it
  uint32_t value = 1;
  char *check = (char*)&value;
  // If first byte is 1, system is little endian
  if(*check) 
  {
    // little endian system
    memcpy(zp, *xp, sizeof(*zp));
  } 
  else 
  {
    // big endian system
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
  }

  *xp += 4;
  *xn -= 4;

  return 1;
}


It evaluates the endianness of the system by creating a 'uint32_t' with the value of 1 and then casting its address to a 'char'. If the first byte of that char value is 1, the system is little endian, otherwise, it's big endian. The function then uses this to appropriately read the value depending on the detected system's endian-ness.