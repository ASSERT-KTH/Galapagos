btc_size_read(size_t *zp, const uint8_t **xp, size_t *xn) {
  uint64_t z;

  if (!btc_compact_read(&z, xp, xn))
    return 0;

  if (z > 0x02000000)
    return 0;

  *zp = z;

  return 1;
}