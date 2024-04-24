BIGNUM *BN_dup(const BIGNUM *src) {
  BIGNUM *copy;

  if (src == NULL) {
    return NULL;
  }

  copy = BN_new();
  if (copy == NULL) {
    return NULL;
  }

  if (!BN_copy(copy, src)) {
    BN_free(copy);
    return NULL;
  }

  return copy;
}