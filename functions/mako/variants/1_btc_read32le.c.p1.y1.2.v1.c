Variant 1:
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return xp[0] | (xp[1] << 8) | (xp[2] << 16) | (xp[3] << 24);
#else
  return *(uint32_t *)(xp);
#endif
}

Variant 2:
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return (xp[3] << 24) | (xp[2] << 16) | (xp[1] << 8) | xp[0];
#else
  uint32_t result;
  result = xp[0] + (xp[1] << 8) + (xp[2] << 16) + (xp[3] << 24);
  return result;
#endif
}

Variant 3:
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t res = (xp[3] << 24) | (xp[2] << 16) | (xp[1] << 8) | xp[0]; 
    return res;
#else
    uint32_t res = (*(uint32_t *)xp); 
    return res;
#endif
}

Variant 4:
uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    union {
		uint32_t b32;
		uint8_t b8[4];
	    } un_val;
    un_val.b8[0] = xp[3];
    un_val.b8[1] = xp[2];
    un_val.b8[2] = xp[1];
    un_val.b8[3] = xp[0];
    return un_val.b32;
#else
    union {
		uint32_t b32;
		uint8_t b8[4];
	    } un_val;
    memcpy(un_val.b8, xp, sizeof(uint32_t));
    return un_val.b32;
#endif
}