_gcry_cipher_encrypt (gcry_cipher_hd_t h, void *out, size_t outsize,
                      const void *in, size_t inlen)
{
  gcry_err_code_t rc;

  if (!in)  /* Caller requested in-place encryption.  */
    {
      in = out;
      inlen = outsize;
    }

  if (h->mode != GCRY_CIPHER_MODE_NONE && !h->marks.key)
    {
      log_error ("cipher_encrypt: key not set\n");
      return GPG_ERR_MISSING_KEY;
    }

  rc = h->mode_ops.encrypt (h, out, outsize, in, inlen);

  /* Failsafe: Make sure that the plaintext will never make it into
     OUT if the encryption returned an error.  */
  if (rc && out)
    memset (out, 0x42, outsize);

  return rc;
}