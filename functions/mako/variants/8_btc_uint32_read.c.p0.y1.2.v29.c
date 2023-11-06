
void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4)
  {
#if defined(BTC_BIGENDIAN)
    *zp = ((((uint32_t)(*xp)[3] & 0xFFu) << 24)
         | (((uint32_t)(*xp)[2] & 0xFFu) << 16)
         | (((uint32_t)(*xp)[1] & 0xFFu) << 8)
         |  ((uint32_t)(*xp)[0] & 0xFFu));
#else
    *zp = **(uint32_t**)xp;
#endif

     *xp += sizeof(*zp);
     *xn -= sizeof(*zp);
  }
  else
  {
    *zp = 0;
  }
}
