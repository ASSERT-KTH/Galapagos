btc_view_get(const btc_view_t *view, const btc_outpoint_t *outpoint) {
  btc_coins_t *coins = btc_view_coins(view, outpoint->hash);

  if (coins == NULL)
    return NULL;

  return btc_coins_get(coins, outpoint->index);
}