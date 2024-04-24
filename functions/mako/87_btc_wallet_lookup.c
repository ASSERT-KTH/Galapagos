btc_wallet_lookup(uint32_t *account, btc_wallet_t *wallet, const char *name) {
  size_t len = strlen(name);

  if (len == 0 || len > 63)
    return 0;

  if (strcmp(name, "*") == 0 ||
      strcmp(name, ".") == 0) {
    return BTC_NO_ACCOUNT;
  }

  return db_get_index(wallet->db, name, account);
}