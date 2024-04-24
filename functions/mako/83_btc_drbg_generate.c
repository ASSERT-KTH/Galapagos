btc_drbg_generate(btc_drbg_t *drbg, void *out, size_t len) {
  uint8_t *raw = (uint8_t *)out;
  btc_hmac256_t kmac;

  while (len > 0) {
    kmac = drbg->kmac;
    btc_hmac256_update(&kmac, drbg->V, 32);
    btc_hmac256_final(&kmac, drbg->V);

    if (len < 32) {
      memcpy(raw, drbg->V, len);
      break;
    }

    memcpy(raw, drbg->V, 32);

    raw += 32;
    len -= 32;
  }

  btc_drbg_update(drbg, NULL, 0);
}