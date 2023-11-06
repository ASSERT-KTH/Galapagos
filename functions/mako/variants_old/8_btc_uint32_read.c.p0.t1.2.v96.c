btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4) {

#if defined(BTC_BIGENDIAN)
    *zp = ((*xp)[0] <<  0)
        ^ ((*xp)[1] <<  8)
        ^ ((*xp)[2] << 16)
        ^ ((*xp)[3] << 24);
#else
    memcpy(zp, *xp, 4);
#endif

    *xp += 4;
    *xn -= 4;

    return 1;
  } else {
    return 0;
  }
}