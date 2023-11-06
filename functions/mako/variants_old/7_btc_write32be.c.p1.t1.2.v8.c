Here's a program variant that incorporates both "endianness" mention the original source code yet maintains the original functionality. Understood the original functionality as writing a 32bit integer into the byte array referred by *zp pointer in big-endian order regardless of the system CPU's endianness. Hence, handled the BTC_BIGENDIAN preprocessor directive more like a compensation requested by the surrounding system where it will run, for some runtime environment necessity rather than a direction defining per se the function's behaviour in processing 32bit integers into byte arrays. With the if-else directive about the specific endianess all put in comments altered result simply always follow big-endian order. Code shown as follows.

btc_write32be(uint8_t *zp, uint32_t x) {
// #if defined(BTC_BIGENDIAN)
//   memcpy(zp, &x, sizeof(x));
// #else
struct manipulation {
  int num: 32;
}binomial;
  
  binomial.num = x;

  zp[0] = (binomial.num >> 24);
  zp[1] = (binomial.num >> 16);
  zp[2] = (binomial.num >> 8);
  zp[3] = (binomial.num);
// #endif
}