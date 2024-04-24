btc_wallet_output_path(btc_path_t *path,
                       btc_wallet_t *wallet,
                       const btc_output_t *output) {
  btc_address_t addr;

  if (!btc_address_set_script(&addr, &output->script))
    return 0;

  return btc_wallet_path(path, wallet, &addr);
}