ldb_varint32_read(uint32_t *z, const uint8_t **xp, size_t *xn) {
  uint32_t result, shift;

  if (LIKELY(*xn > 0)) {
    result = **xp;

    if ((result & 128) == 0) {
      *xp += 1;
      *xn -= 1;
      *z = result;
      return 1;
    }
  }

  result = 0;

  for (shift = 0; shift <= 28 && *xn > 0; shift += 7) {
    uint32_t byte = **xp;

    *xp += 1;
    *xn -= 1;

    if (byte & 128) {
      result |= ((byte & 127) << shift);
    } else {
      result |= (byte << shift);
      *z = result;
      return 1;
    }
  }

  *z = 0;

  return 0;
}