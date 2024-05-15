gcry_pk_hash_verify (gcry_sexp_t sigval, const char *data_tmpl, gcry_sexp_t pkey,
                     gcry_md_hd_t hd, gcry_ctx_t ctx)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());
  return gpg_error (_gcry_pk_verify_md (sigval, data_tmpl, hd, pkey, ctx));
}