The following refactored code variation maintains the functionality of the original code but uses an entirely different way to extract four bytes from the input byte array and pack them into a 32-bit integer considering the host system's endianness:


#include <stdint.h>
#include <stddef.h>

int btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  *zp = 0;

#if defined(BTC_BIGENDIAN)
    for(int i = 0; i < 4; i++){
        *zp |= (*xp)[i] << (i * 8);
    }
#else
    for(int i = 0; i < 4; i++){
        *zp |= (*xp)[i] << ((3 - i) * 8);
    }
#endif

  *xp += 4;
  *xn -= 4;

  return 1;
}


Instead of bitwise operators (|, <<) over four bytes in one octave or memcpy(), this code repeatedly applies bitwise operators to each byte separately with loop which enables more flexible use of shifting scale. The starting point of iterations are different according to host system's endianness. This digital representation ensures bitwise operations are properly accumulated on target container while simplicity made by loop enhances readability of the code.