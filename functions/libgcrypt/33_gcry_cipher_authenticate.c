gcry_cipher_authenticate (gcry_cipher_hd_t hd, const void *abuf, size_t abuflen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gpg_error (_gcry_cipher_authenticate (hd, abuf, abuflen));
}