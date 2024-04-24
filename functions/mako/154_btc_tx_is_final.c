btc_tx_is_final(const btc_tx_t *tx, int32_t height, int64_t time) {
  static unsigned int threshold = BTC_LOCKTIME_THRESHOLD;
  size_t i;

  if (tx->locktime == 0)
    return 1;

  if ((int64_t)tx->locktime < (tx->locktime < threshold ? height : time))
    return 1;

  for (i = 0; i < tx->inputs.length; i++) {
    if (tx->inputs.items[i]->sequence != 0xffffffff)
      return 0;
  }

  return 1;
}