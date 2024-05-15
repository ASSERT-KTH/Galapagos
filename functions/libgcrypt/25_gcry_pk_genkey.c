gcry_pk_genkey (gcry_sexp_t *r_key, gcry_sexp_t s_parms)
{
  if (!fips_is_operational ())
    {
      *r_key = NULL;
      return gpg_error (fips_not_operational ());
    }
  return gpg_error (_gcry_pk_genkey (r_key, s_parms));
}