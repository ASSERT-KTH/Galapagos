gcry_mac_write (gcry_mac_hd_t hd, const void *buf, size_t buflen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gpg_error (_gcry_mac_write (hd, buf, buflen));
}