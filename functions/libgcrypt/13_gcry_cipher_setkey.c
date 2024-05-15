gcry_cipher_setkey (gcry_cipher_hd_t hd, const void *key, size_t keylen)
{
  if (!fips_is_operational ())
    return gpg_error (fips_not_operational ());

  return gcry_error (_gcry_cipher_setkey (hd, key, keylen));
}