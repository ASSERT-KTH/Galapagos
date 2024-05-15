gcry_cipher_gettag (gcry_cipher_hd_t hd, void *outtag, size_t taglen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gpg_error (_gcry_cipher_gettag (hd, outtag, taglen));
}