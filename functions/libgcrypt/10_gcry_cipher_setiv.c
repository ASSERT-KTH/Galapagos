gcry_cipher_setiv (gcry_cipher_hd_t hd, const void *iv, size_t ivlen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gcry_error (_gcry_cipher_setiv (hd, iv, ivlen));
}