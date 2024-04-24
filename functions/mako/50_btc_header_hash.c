btc_header_hash(uint8_t *hash, const btc_header_t *hdr) {
  btc_hash256_t ctx;

  btc_hash256_init(&ctx);

  btc_uint32_update(&ctx, hdr->version);
  btc_raw_update(&ctx, hdr->prev_block, 32);
  btc_raw_update(&ctx, hdr->merkle_root, 32);
  btc_time_update(&ctx, hdr->time);
  btc_uint32_update(&ctx, hdr->bits);
  btc_uint32_update(&ctx, hdr->nonce);

  btc_hash256_final(&ctx, hash);
}