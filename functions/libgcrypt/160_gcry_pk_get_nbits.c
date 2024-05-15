gcry_pk_get_nbits (gcry_sexp_t key)
{
  if (!fips_is_operational ())
    {
      (void)fips_not_operational ();
      return 0;
    }

  return _gcry_pk_get_nbits (key);
}