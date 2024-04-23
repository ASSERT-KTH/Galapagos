unsigned BN_num_bits(const BIGNUM *bn) {
  const int width = bn_minimal_width(bn);
  if (width == 0) {
    return 0;
  }

  return (width - 1) * BN_BITS2 + BN_num_bits_word(bn->d[width - 1]);
}