gcry_cipher_ctl (gcry_cipher_hd_t h, int cmd, void *buffer, size_t buflen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gpg_error (_gcry_cipher_ctl (h, cmd, buffer, buflen));
}