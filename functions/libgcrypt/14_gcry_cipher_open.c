gcry_cipher_open (gcry_cipher_hd_t *handle,
                  int algo, int mode, unsigned int flags)
{
  if (!fips_is_operational ())
    {
      *handle = NULL;
      return gpg_error (fips_not_operational ());
    }

  return gpg_error (_gcry_cipher_open (handle, algo, mode, flags));
}