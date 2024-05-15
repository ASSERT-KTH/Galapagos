gcry_pk_encrypt (gcry_sexp_t *result, gcry_sexp_t data, gcry_sexp_t pkey)
{
  if (!fips_is_operational ())
    {
      *result = NULL;
      return gpg_error (fips_not_operational ());
    }
  return gpg_error (_gcry_pk_encrypt (result, data, pkey));
}