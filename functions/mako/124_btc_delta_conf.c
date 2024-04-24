btc_delta_conf(btc_delta_t *delta, const btc_path_t *path, int64_t value) {
  btc_delta_get(delta, path->account)->confirmed += value;

  if (!(path->account & BTC_BIP32_HARDEN))
    delta->balance.confirmed += value;
  else
    delta->watched.confirmed += value;
}