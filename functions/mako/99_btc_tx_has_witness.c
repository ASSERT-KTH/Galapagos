btc_tx_has_witness(const btc_tx_t *tx) {
  size_t i;

  for (i = 0; i < tx->inputs.length; i++) {
    if (tx->inputs.items[i]->witness.length > 0)
      return 1;
  }

  return 0;
}