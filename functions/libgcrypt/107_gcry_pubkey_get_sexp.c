gcry_pubkey_get_sexp (gcry_sexp_t *r_sexp, int mode, gcry_ctx_t ctx)
{
  if (!fips_is_operational ())
    {
      *r_sexp = NULL;
      return gpg_error (fips_not_operational ());
    }
  return gpg_error (_gcry_pubkey_get_sexp (r_sexp, mode, ctx));
}