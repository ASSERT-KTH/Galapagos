btc_chain_throw(btc_chain_t *chain,
                const btc_header_t *header,
                unsigned int code,
                const char *reason,
                int score,
                int malleated) {
  const char *str = btc_reject_code(code);
  uint8_t *hash = chain->error.hash;

  btc_header_hash(hash, header);

  chain->error.code = code;
  chain->error.reason = reason;
  chain->error.score = score;
  chain->error.malleated = malleated;

  btc_log_warn(chain, "Verification error: %s (code=%s score=%d hash=%H)",
                      reason, str, score, hash);

  return 0;
}