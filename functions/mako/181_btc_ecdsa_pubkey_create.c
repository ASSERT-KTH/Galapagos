btc_ecdsa_pubkey_create(unsigned char *pub,
                        const unsigned char *priv,
                        int compact) {
  int ret = 1;
  wge_t A;
  sc_t a;

  ret &= sc_import(a, priv);
  ret &= sc_is_zero(a) ^ 1;

  wei_mul_g(&A, a);

  ret &= wge_export(pub, &A, compact);

  sc_cleanse(a);
  wge_cleanse(&A);

  return ret;
}