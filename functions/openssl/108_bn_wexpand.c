int bn_wexpand(BIGNUM *bn, size_t words) {
  BN_ULONG *a;

  if (words <= (size_t)bn->dmax) {
    return 1;
  }

  if (words > (INT_MAX / (4 * BN_BITS2))) {
    OPENSSL_PUT_ERROR(BN, BN_R_BIGNUM_TOO_LONG);
    return 0;
  }

  if (bn->flags & BN_FLG_STATIC_DATA) {
    OPENSSL_PUT_ERROR(BN, BN_R_EXPAND_ON_STATIC_BIGNUM_DATA);
    return 0;
  }

  a = OPENSSL_malloc(sizeof(BN_ULONG) * words);
  if (a == NULL) {
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    return 0;
  }

  OPENSSL_memcpy(a, bn->d, sizeof(BN_ULONG) * bn->width);

  OPENSSL_free(bn->d);
  bn->d = a;
  bn->dmax = (int)words;

  return 1;
}