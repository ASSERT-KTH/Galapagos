btc_peer_increase_ban(btc_peer_t *peer, int score) {
  peer->ban_score += score;

  if (peer->ban_score >= BTC_NET_BAN_SCORE) {
    btc_peer_debug(peer, "Ban threshold exceeded (%N).", &peer->addr);
    btc_pool_ban(peer->pool, &peer->addr);
    return 1;
  }

  return 0;
}