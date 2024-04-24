btc_delta_coin(btc_delta_t *delta, const btc_path_t *path, int64_t value) {
  btc_delta_get(delta, path->account)->coin += value;

  if (!(path->account & BTC_BIP32_HARDEN))
    delta->balance.coin += value;
  else
    delta->watched.coin += value;
}