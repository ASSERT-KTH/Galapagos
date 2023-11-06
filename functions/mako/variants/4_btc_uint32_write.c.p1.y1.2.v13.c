Variant 1:

buzz_uint32_write(uint8_t *jp, uint32_t m) {
  #if defined(BUZZ_BIGENDIAN)
    *jp++ = (m >>  0);
    *jp++ = (m >>  8);
    *jp++ = (m >> 16);
    *jp++ = (m >> 24);
    return jp;
  #else
    memcpy(jp, &m, sizeof(m));
    return jp + 4;
  #endif
}

Variant 2:

fid_uint32_write(uint8_t *ip, uint32_t y) {
  #if defined(FID_BIGENDIAN)
    *ip++ = (y >>  0);
    *ip++ = (y >>  8);
    *ip++ = (y >> 16);
    *ip++ = (y >> 24);
    return ip;
  #else
    memcpy(ip, &y, sizeof(y));
    return ip + 4;
  #endif
}

Variant 3:

thg_uint32_write(uint8_t *up, uint32_t z) {
  #if defined(THG_BIGENDIAN)
    *up++ = (z >>  0);
    *up++ = (z >>  8);
    *up++ = (z >> 16);
    *up++ = (z >> 24);
    return up;
  #else
    memcpy(up, &z, sizeof(z));
    return up + 4;
  #endif
}
