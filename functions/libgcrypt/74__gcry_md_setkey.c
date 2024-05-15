_gcry_md_setkey (gcry_md_hd_t hd, const void *key, size_t keylen)
{
  gcry_err_code_t rc;

  if (hd->ctx->flags.hmac)
    {
      rc = prepare_macpads (hd, key, keylen);
      if (!rc)
	_gcry_md_reset (hd);
    }
  else
    {
      rc = md_setkey (hd, key, keylen);
    }

  return rc;
}