gcry_md_copy (gcry_md_hd_t *bhd, gcry_md_hd_t ahd)
{
  if (!fips_is_operational ())
    {
      *bhd = NULL;
      return gpg_error (fips_not_operational ());
    }
  return gpg_error (_gcry_md_copy (bhd, ahd));
}