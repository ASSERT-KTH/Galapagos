int BN_cmp(const BIGNUM *a, const BIGNUM *b) {
  if ((a == NULL) || (b == NULL)) {
    if (a != NULL) {
      return -1;
    } else if (b != NULL) {
      return 1;
    } else {
      return 0;
    }
  }

  // We do not attempt to process the sign bit in constant time. Negative
  // |BIGNUM|s should never occur in crypto, only calculators.
  if (a->neg != b->neg) {
    if (a->neg) {
      return -1;
    }
    return 1;
  }

  int ret = BN_ucmp(a, b);
  return a->neg ? -ret : ret;
}