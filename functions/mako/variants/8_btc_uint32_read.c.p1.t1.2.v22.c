Here is a variant of the function provided that changes its behavior, maintaining the original functionality of the function. This mainly uses an alternate way of right-shifting the bytes with the use of union and puts a check on platform endianness at runtime rather than compile time.


#include<stdbool.h>
#include<endian.h>

btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  // create a union holding uint32_t and uint8_t array of size 4
  union {
    uint32_t number;
    uint8_t array[4];
  } union_var;

  for(int i = 0; i < 4; i++)
    union_var.array[i] = (*xp)[i];

  if (__BYTE_ORDER == __BIG_ENDIAN)
    *zp = (union_var.array[0] <<  0)
        | (union_var.array[1] <<  8)
        | (union_var.array[2] << 16)
        | (union_var.array[3] << 24);
  else
    *zp = union_var.number;

  *xp += 4;
  *xn -= 4;
  return 1;
}
