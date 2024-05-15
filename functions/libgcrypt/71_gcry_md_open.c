gcry_md_open (gcry_md_hd_t *h, int algo, unsigned int flags)
{
  if (!fips_is_operational ())
    {
      *h = NULL;
      return gpg_error (fips_not_operational ());
    }

  return gpg_error (_gcry_md_open (h, algo, flags));
}