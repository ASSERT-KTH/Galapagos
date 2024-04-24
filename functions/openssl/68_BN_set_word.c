int BN_set_word(BIGNUM *bn, BN_ULONG value) {
  if (value == 0) {
    BN_zero(bn);
    return 1;
  }

  if (!bn_wexpand(bn, 1)) {
    return 0;
  }

  bn->neg = 0;
  bn->d[0] = value;
  bn->width = 1;
  return 1;
}