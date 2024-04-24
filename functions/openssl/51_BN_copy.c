BIGNUM *BN_copy(BIGNUM *dest, const BIGNUM *src) {
  if (src == dest) {
    return dest;
  }

  if (!bn_wexpand(dest, src->width)) {
    return NULL;
  }

  OPENSSL_memcpy(dest->d, src->d, sizeof(src->d[0]) * src->width);

  dest->width = src->width;
  dest->neg = src->neg;
  return dest;
}