btc_write32be(uint8_t *zp, uint32_t y) {
#if defined(BTC_BIGENDIAN)
 memcpy(zp, &y, sizeof(y));
#else
 zp[3] = ((uint8_t)(y));
 zp[2] = ((uint8_t)(y >> 8));
 zp[1] = ((uint8_t)(y >> 16));
 zp[0] = ((uint8_t)(y >> 24));
#endif 
}