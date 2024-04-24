btc_delta_unconf(btc_delta_t *delta, const btc_path_t *path, int64_t value) {
  btc_delta_get(delta, path->account)->unconfirmed += value;

  if (!(path->account & BTC_BIP32_HARDEN))
    delta->balance.unconfirmed += value;
  else
    delta->watched.unconfirmed += value;
}