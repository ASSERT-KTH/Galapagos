twofish_setkey (void *context, const byte *key, unsigned int keylen,
                cipher_bulk_ops_t *bulk_ops)
{
  TWOFISH_context *ctx = context;
  unsigned int hwfeatures = _gcry_get_hw_features ();
  int rc;

  rc = do_twofish_setkey (ctx, key, keylen);

#ifdef USE_AVX2
  ctx->use_avx2 = (hwfeatures & HWF_INTEL_AVX2) != 0;
#endif

  /* Setup bulk encryption routines.  */
  memset (bulk_ops, 0, sizeof(*bulk_ops));
  bulk_ops->cbc_dec = _gcry_twofish_cbc_dec;
  bulk_ops->cfb_dec = _gcry_twofish_cfb_dec;
  bulk_ops->ctr_enc = _gcry_twofish_ctr_enc;
  bulk_ops->ocb_crypt = _gcry_twofish_ocb_crypt;
  bulk_ops->ocb_auth = _gcry_twofish_ocb_auth;
  bulk_ops->xts_crypt = _gcry_twofish_xts_crypt;
  bulk_ops->ecb_crypt = _gcry_twofish_ecb_crypt;

  (void)hwfeatures;

  _gcry_burn_stack (23+6*sizeof(void*));
  return rc;
}