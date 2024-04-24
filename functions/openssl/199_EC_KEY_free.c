void EC_KEY_free(EC_KEY *r) {
  if (r == NULL) {
    return;
  }

  if (!CRYPTO_refcount_dec_and_test_zero(&r->references)) {
    return;
  }

  if (r->ecdsa_meth) {
    if (r->ecdsa_meth->finish) {
      r->ecdsa_meth->finish(r);
    }
    METHOD_unref(r->ecdsa_meth);
  }

  EC_GROUP_free(r->group);
  EC_POINT_free(r->pub_key);
  ec_wrapped_scalar_free(r->priv_key);

  CRYPTO_free_ex_data(g_ec_ex_data_class_bss_get(), r, &r->ex_data);

  OPENSSL_free(r);
}