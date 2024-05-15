static gcry_err_code_t blake2b_init_ctx(void *ctx, unsigned int flags,
					const byte *key, size_t keylen,
					unsigned int dbits)
{
  BLAKE2B_CONTEXT *c = ctx;
  unsigned int features = _gcry_get_hw_features ();

  (void)features;
  (void)flags;

  memset (c, 0, sizeof (*c));

#ifdef USE_AVX2
  c->use_avx2 = !!(features & HWF_INTEL_AVX2);
#endif
#ifdef USE_AVX512
  c->use_avx512 = !!(features & HWF_INTEL_AVX512);
#endif

  c->outlen = dbits / 8;
  c->buflen = 0;
  return blake2b_init(c, key, keylen);
}