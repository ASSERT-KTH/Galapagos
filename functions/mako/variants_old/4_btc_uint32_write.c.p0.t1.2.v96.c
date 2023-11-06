btc_uint32_write(uint8_t* zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
 zp[0] = (x >>  0);
 zp[1] = (x >>  8);
 zp[2] = (x >> 16);
 zp[3] = (x >> 24);
 return zp + sizeof(x);
#else
 uint8_t* temp_pos = zp;
 memcpy(temp_pos, &x, sizeof(x));
 return temp_pos + sizeof(uint32_t);
#endif
}