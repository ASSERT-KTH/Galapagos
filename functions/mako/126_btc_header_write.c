btc_header_write(uint8_t *zp, const btc_header_t *x) {
  zp = btc_uint32_write(zp, x->version);
  zp = btc_raw_write(zp, x->prev_block, 32);
  zp = btc_raw_write(zp, x->merkle_root, 32);
  zp = btc_time_write(zp, x->time);
  zp = btc_uint32_write(zp, x->bits);
  zp = btc_uint32_write(zp, x->nonce);
  return zp;
}