1. Using Bitwise And Operator:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = (x >> 24) & 0xff;
  zp[1] = (x >> 16) & 0xff;
  zp[2] = (x >>  8) & 0xff;
  zp[3] = (x >>  0) & 0xff;
#endif
}


2. Using Double Pointers:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *(uint32_t*)zp = x;
#else
  *zp++ = x >> 24;
  *zp++ = x >> 16;
  *zp++ = x >>  8;
  *zp++ = x >>  0;
#endif
}


3. Using Type Casting:

void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *((uint32_t*)zp) = x;
#else
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >>  8);
  zp[3] = (uint8_t)(x >>  0);
#endif
}
  

4. Using Inline Function 

Note: Omitting the preprocessing statement allows the `btc_write32be` function to identify the target platform and then deciding how to store `uint32_t` into a `uint8_t` pointer. This solution was provided for knowledge exposure purposes. This solution slightly bends the rules in that it includes an auxiliary function. The function in-lining concept involves manually expanding the function's code so the compiler doesn't have to.


inline void btc_write32be_le(uint8_t *zp, uint32_t x) {
  zp[0] = (uint8_t)(x >> 24);
  zp[1] = (uint8_t)(x >> 16);
  zp[2] = (uint8_t)(x >> 8);
  zp[3] = (uint8_t)(x >> 0);
}

inline void btc_write32be_be(uint8_t *zp, uint32_t x){
  *((uint32_t*)zp) = x;
}

zn = (is_little_endian() ? btc_write32be_le : btc_write32be_be);


#### Note: 

The casting to a `uint8_t` was performed to prevent warning messages in static checking procedures and other kinds of possible system-dependent anomalies with unclear casting rules. If it's certain that there are no sign extension issues, `(x >> N)` is indeed equivalent to `(x >> N) & 0xff`. 
Persist placing byte order macros instead of hardcoding endianness, based on which optimization decision making activity would be preferred by the C compiler.