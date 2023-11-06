The original function essentially takes a 32-bit number and stores it into a byte array. To maintain its original functionality, we can make use of stl bitset in C++ to implement this, the bitset container stores its content as bits (boolean values), providing useful manipulation ways. This maintains the original function of storing 32 bit integer data in byte format keeping either big endian formatting if defined or the format in which system stores integer values. Here is a code variant:

++
#include <bitset>
#include <cstdint>

uint8_t* btc_uint32_write(uint8_t *zp, uint32_t x) {
  std::bitset<sizeof(uint32_t)*8> bs(x);
#if defined(BTC_BIGENDIAN)
    for (int i = sizeof(uint32_t)-1; i >= 0; i--) {
      *(zp++) = bs.to_ulong() >> (8*i);
  }
  return zp;
#else
  std::bitset<sizeof(uint8_t)*8> arr[sizeof(uint32_t)];
  for(int i = 0; i < sizeof(uint32_t); i++){
    for(int j = 0; j < 8;j++){
      arr[i][j] = bs[8*i + j];
    }
    *zp = arr[i].to_ulong();
    zp++;
  }
  return zp;
#endif
}

Note: This code uses data level endian compatiblity for transforming into byte sequences but may not always work on machine-level as the endianness of machine dictates the way memory operations are carried out.