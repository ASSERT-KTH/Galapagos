The requested alternative can be designed using the ntohs functionality for ensuring Endianness correction and treats the input array as a network byte ordered array.


#include <arpa/inet.h>

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;
    
  memcpy(zp, *xp, sizeof(*zp));
  *zp = ntohl(*zp);
  *xp += 4;
  *xn -= 4;
  return 1;
}


Here ntohl() ensures portability across different systems, it will changes the endianness of a uint_32 if the system is on a Little Endian Arch. If already on Big Endian arch, it will do nothing.
This variant implementation thus fulfills all original roles of this function but changes its internal implementation, thereby satisfying the given request.