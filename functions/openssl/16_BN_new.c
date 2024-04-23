BIGNUM *BN_new(void) {
  BIGNUM *bn = OPENSSL_malloc(sizeof(BIGNUM));

  if (bn == NULL) {
    OPENSSL_PUT_ERROR(BN, ERR_R_MALLOC_FAILURE);
    return NULL;
  }

  OPENSSL_memset(bn, 0, sizeof(BIGNUM));
  bn->flags = BN_FLG_MALLOCED;

  return bn;
}