gcry_pk_hash_sign (gcry_sexp_t *result, const char *data_tmpl, gcry_sexp_t skey,
                   gcry_md_hd_t hd, gcry_ctx_t ctx)
{
  if (!fips_is_operational ())
    {
      *result = NULL;
      return gpg_error (fips_not_operational ());
    }
  return gpg_error (_gcry_pk_sign_md (result, data_tmpl, hd, skey, ctx));
}