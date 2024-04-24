btc_bloom_add(btc_bloom_t *bloom, const uint8_t *val, size_t len) {
  uint32_t i;

  if (bloom->size == 0)
    return;

  for (i = 0; i < bloom->n; i++) {
    size_t bit = btc_bloom_hash(bloom, val, len, i);

    bloom->data[bit >> 3] |= (1 << (bit & 7));
  }
}