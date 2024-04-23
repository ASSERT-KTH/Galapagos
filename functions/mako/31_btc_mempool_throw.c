btc_mempool_throw(btc_mempool_t *mp,
                  const btc_tx_t *tx,
                  unsigned int code,
                  const char *reason,
                  int score,
                  int malleated) {
  const char *str = btc_reject_code(code);

  btc_log_warn(mp, "Verification error: %s (code=%s score=%d hash=%H)",
                   reason, str, score, tx->hash);

  return btc_mempool_fail(mp, tx, code, reason, score, malleated);
}