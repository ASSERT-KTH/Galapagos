btc_wallet_path(btc_path_t *path,
                btc_wallet_t *wallet,
                const btc_address_t *addr) {
  if (!btc_bloom_has(&wallet->filter, addr->hash, addr->length))
    return 0;

  return db_get_path(wallet->db, addr, path);
}