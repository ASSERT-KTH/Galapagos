The original function does not return anything, so without specified conditions on which to base any modification, the behavioral change can take many forms. For instance, the division of actions by endianness could be relocated to select between two different function expressions:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
    for(int i = 0; i < sizeof(x); ++i)
        zp[i] = ((x >> ((sizeof(x) - 1 - i) * 8)) & 0xFF);
#else
    for(int i = 0; i < sizeof(x); ++i)
        zp[i] = ((x >> ((sizeof(x) - 1 - i) * 8)) & 0xFF);
#endif
}

This program keeps the original functionality of writing 32-bit data to an array, but does so by iterating over each byte of the data and manually moving it to the correct location, offering a behavioural change while maintaining the original functionality. Add only one direction, ie only for big endian or for little endian system you do not need both loops. For little endian system it could be revised as:


void btc_write32be(uint8_t *zp, uint32_t x) {
  for(int i = 0; i < sizeof(x); ++i)
    zp[sizeof(x) - 1 - i] = (x >> (i * 8)) & 0xFF;
}
