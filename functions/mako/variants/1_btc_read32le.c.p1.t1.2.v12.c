
uint32_t btc_read32le(const uint8_t *xp) {
  union {
    uint8_t bytes[4];
    uint32_t integer;
  } myUnion;

#if defined(BTC_BIGENDIAN)
    myUnion.bytes[0] = xp[0];
    myUnion.bytes[1] = xp[1];
    myUnion.bytes[2] = xp[2];
    myUnion.bytes[3] = xp[3];
    return myUnion.integer;
#else
    memcpy(myUnion.bytes, xp, sizeof(myUnion.bytes));
    return myUnion.integer;
#endif
}
