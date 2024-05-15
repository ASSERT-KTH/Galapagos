gcry_md_write (gcry_md_hd_t hd, const void *buffer, size_t length)
{
  if (!fips_is_operational ())
    {
      (void)fips_not_operational ();
      return;
    }
  _gcry_md_write (hd, buffer, length);
}