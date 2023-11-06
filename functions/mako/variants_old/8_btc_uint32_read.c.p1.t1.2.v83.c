Here's a variant version using the ternary operator clause:
 
btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
if (*xn < 4)
  return 0;

*zn = (defined(BTC_BIGENDIAN)) ? 
  ((uint32_t)(*xp)[0] <<  0)
| ((uint32_t)(*xp)[1] <<  8)
| ((uint32_t)(*xp)[2] << 16)
| ((uint32_t)(*xp)[3] << 24) 
: 
memcpy(zp, *xp, sizeof(*zp)); 

*xp += 4;
*xn -= 4;

return 1;
}

The functionality of the code remains as it is but the behaviour is altered in terms of code structure by compacting the big endian check and corresponding operations into a single ternary operation. The ternary operator clause is more readable than the multi-line if/else constructs for such singular condition-addressed occurrences.
Note: That 'ternary operator' approach doesn't always deliver better code readability. For more complex conditions, conventional if/else constructs would be better.