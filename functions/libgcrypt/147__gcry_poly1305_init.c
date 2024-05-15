_gcry_poly1305_init (poly1305_context_t * ctx, const byte * key,
		     size_t keylen)
{
  static int initialized;
  static const char *selftest_failed;

  if (!initialized)
    {
      initialized = 1;
      selftest_failed = selftest ();
      if (selftest_failed)
	log_error ("Poly1305 selftest failed (%s)\n", selftest_failed);
    }

  if (keylen != POLY1305_KEYLEN)
    return GPG_ERR_INV_KEYLEN;

  if (selftest_failed)
    return GPG_ERR_SELFTEST_FAILED;

  poly1305_init (ctx, key);

  return 0;
}