btc_peer_sendmsg(btc_peer_t *peer, enum btc_msgtype type, const void *body) {
  btc_msg_t msg;

  btc_msg_set_type(&msg, type);

  msg.body = (void *)body;

  return btc_peer_send(peer, &msg);
}