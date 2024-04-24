btc_tx_verify(const btc_tx_t *tx, const btc_view_t *view, unsigned int flags) {
  const btc_input_t *input;
  const btc_coin_t *coin;
  btc_tx_cache_t cache;
  size_t i;

  memset(&cache, 0, sizeof(cache));

  for (i = 0; i < tx->inputs.length; i++) {
    input = tx->inputs.items[i];
    coin = btc_view_get(view, &input->prevout);

    if (coin == NULL)
      return 0;

    if (!btc_tx_verify_input(tx, i, &coin->output, flags, &cache))
      return 0;
  }

  return 1;
}