gcry_cipher_encrypt (gcry_cipher_hd_t h,
                     void *out, size_t outsize,
                     const void *in, size_t inlen)
{
  if (!fips_is_operational ())
    {
      /* Make sure that the plaintext will never make it to OUT. */
      if (out)
        memset (out, 0x42, outsize);
      return gpg_error (fips_not_operational ());
    }

  return gpg_error (_gcry_cipher_encrypt (h, out, outsize, in, inlen));
}