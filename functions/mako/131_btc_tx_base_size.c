btc_tx_base_size(const btc_tx_t *tx) {
  size_t size = 0;

  size += 4;
  size += btc_inpvec_size(&tx->inputs);
  size += btc_outvec_size(&tx->outputs);
  size += 4;

  return size;
}