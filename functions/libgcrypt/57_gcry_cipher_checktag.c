gcry_cipher_checktag (gcry_cipher_hd_t hd, const void *intag, size_t taglen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gpg_error (_gcry_cipher_checktag (hd, intag, taglen));
}