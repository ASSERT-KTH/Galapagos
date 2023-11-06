btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  // Assuming in turn system rotates things 8 bits, 4 times, bringing each byte to the MSB
  uint32_t t_x = ((x << 24) | 
               ((x << 8) & 0x00ff0000) |
               ((x >> 8) & 0x0000ff00) |
               (x >> 24));
  memcpy(zp, &t_x, sizeof(x));
#else
  //direct implementation for small endian
  zp[0] = static_cast<uint8_t>(x >> 24);
  zp[1] = static_cast<uint8_t>((x >> 16) & 0x000000FF);
  zp[2] = static_cast<uint8_t>((x >> 8) & 0x000000FF);
  zp[3] = static_cast<uint8_t>(x & 0x000000FF);
#endif
}