_gcry_cipher_open (gcry_cipher_hd_t *handle,
                   int algo, int mode, unsigned int flags)
{
  gcry_err_code_t rc;
  gcry_cipher_hd_t h = NULL;

  if (mode >= GCRY_CIPHER_MODE_INTERNAL)
    rc = GPG_ERR_INV_CIPHER_MODE;
  else
    rc = _gcry_cipher_open_internal (&h, algo, mode, flags);

  *handle = rc ? NULL : h;

  return rc;
}