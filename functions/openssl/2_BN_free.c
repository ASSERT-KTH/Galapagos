void BN_free(BIGNUM *bn) {
  if (bn == NULL) {
    return;
  }

  if ((bn->flags & BN_FLG_STATIC_DATA) == 0) {
    OPENSSL_free(bn->d);
  }

  if (bn->flags & BN_FLG_MALLOCED) {
    OPENSSL_free(bn);
  } else {
    bn->d = NULL;
  }
}