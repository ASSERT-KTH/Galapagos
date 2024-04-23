btc_log(btc_wallet_t *wallet, int level, const char *fmt, ...) {
  const btc_wclient_t *client = &wallet->client;
  va_list ap;

  va_start(ap, fmt);

  if (client->log != NULL) {
    client->log(client->state, level, fmt, ap);
  } else {
    btc_vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
  }

  va_end(ap);
}