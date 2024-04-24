btc_filter_has(const btc_filter_t *filter, const uint8_t *val, size_t len) {
  uint32_t hash;
  uint64_t bits;
  size_t pos;
  int i, bit;

  if (filter->length == 0)
    return 0;

  for (i = 0; i < filter->n; i++) {
    hash = btc_filter_hash(filter, val, len, i);
    bit = hash & 0x3f;
    pos = (hash >> 6) % filter->length;
    bits = filter->data[pos & ~1] | filter->data[pos | 1];

    if (((bits >> bit) & 1) == 0)
      return 0;
  }

  return 1;
}