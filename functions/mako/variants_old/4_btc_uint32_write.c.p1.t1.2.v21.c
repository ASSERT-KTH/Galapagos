Here is a variant that maintains the original functionality, essentially just rewrites the endian check into the main body of the function and applies different branch logic based on it.


#include<stdint.h>
void *btc_uint32_write(uint8_t *zp, uint32_t x) {
  int big_endian = 1;
  big_endian = !((char*)&big_endian)[0];

  if(big_endian) {
    *zp++ = (x >>  0);
    *zp++ = (x >>  8);
    *zp++ = (x >> 16);
    *zp++ = (x >> 24);
  } else {
    memcpy(zp, &x, sizeof(x));
    zp += 4;
  }
  
  return zp;  
}

This modified version performs a runtime check to identify the endianness of the system. Then, based on this, it applies the suitable byte-shift or memcopy operation. It returns a pointer to the block of memory linked to the bit storage pile. The existing code's function signature isn't changed in any way, thereby ensuring interface compatibility with any other function calls within the preexisting body of the project. 

Besides, please take a note of the revised function return type. Your initial function had no specified return type which might result in a compilation error. because in ANSI C The default return type is int, whereas here the function returns a pointer ('zp').