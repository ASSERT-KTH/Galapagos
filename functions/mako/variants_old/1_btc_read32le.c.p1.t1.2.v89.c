Here is an equivalent variant of the original C function:



btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
   uint32_t val = 0;
   for (int i = 0; i < 4; i++) {
       val = (val << 8) | xp[i];
   }
   return val;
#else
   uint32_t z;
   z = xp[0] |xp[1]<<8 | xp[2]<<16 | xp[3]<<24;
   return z;
#endif
}

In the big-endian branch, a loop is introduced to perform the bitwise extension and shifting operation. In the little-endian branch, the code is re-written using bitwise OR operation for brevity without any change to how it works. The order of the operations perform are still executed based on previous setup.