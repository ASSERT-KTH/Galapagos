btc_header_copy(btc_header_t *z, const btc_header_t *x) {
  z->version = x->version;
  btc_hash_copy(z->prev_block, x->prev_block);
  btc_hash_copy(z->merkle_root, x->merkle_root);
  z->time = x->time;
  z->bits = x->bits;
  z->nonce = x->nonce;
}