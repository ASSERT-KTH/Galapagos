btc_wallet_account(btc_account_t *acct,
                   btc_wallet_t *wallet,
                   uint32_t account) {
  if (account == BTC_NO_ACCOUNT)
    account = 0;

  btc_account_init(acct, (btc_bloom_t *)&wallet->filter);

  return db_get_account(wallet->db, account, acct);
}