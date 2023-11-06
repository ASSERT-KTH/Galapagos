uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  (*zp) = ((*xp)[3]) |
          ((*xp)[2] << 8) |
          ((*xp)[1] << 16) |
          ((*xp)[0] << 24);
#else
  (*zp) = (**xp);
  (*zp) |= (*(*xp + 1)<<8);
  (*zp) |= (*(*xp + 2)<<16);
  (*zp) |= (*(*xp + 3)<<24);
#endif

  (*xp) += sizeof(*zp);
   (*xn) -= sizeof(*zp);

  return 1;
}