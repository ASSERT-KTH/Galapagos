
void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  *zp++ = (x >> 24) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 8) & 0xFF;
  *zp++ = (x >> 0) & 0xFF;
#else
  *zp++ = x & 0xFF;
  *zp++ = (x >> 8) & 0xFF;
  *zp++ = (x >> 16) & 0xFF;
  *zp++ = (x >> 24) & 0xFF;
#endif
}

I have removed the "return" lines since the function is void. Additional to this, the writing order for each block of bytes is dependent on the Endianess (order of bytes in memory) of the environment. The BTC_BIGENDIAN builds now write the uchar buffer from most significant to least significant byte, and the regular build writes the bytes from least significant to most significant. Taking a further step by using the bitwise operation using "& 0xFF" following the right shift operation, effectively and specifically extracts the specific byte where needed from "x". This implements essentially the same as memcpy in the "else" section of the initial function and properly represents Big Endian interpretation in the former section.