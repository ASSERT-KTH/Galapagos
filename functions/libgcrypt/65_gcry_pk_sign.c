gcry_pk_sign (gcry_sexp_t *result, gcry_sexp_t data, gcry_sexp_t skey)
{
  if (!fips_is_operational ())
    {
      *result = NULL;
      return gpg_error (fips_not_operational ());
    }
  return gpg_error (_gcry_pk_sign (result, data, skey));
}