_gcry_cipher_setiv (gcry_cipher_hd_t c, const void *iv, size_t ivlen)
{
  if (c->mode == GCRY_CIPHER_MODE_GCM)
    {
      c->u_mode.gcm.disallow_encryption_because_of_setiv_in_fips_mode = 0;

      if (fips_mode ())
        {
          /* Direct invocation of GCM setiv in FIPS mode disables encryption. */
          c->u_mode.gcm.disallow_encryption_because_of_setiv_in_fips_mode = 1;
        }
    }

  return c->mode_ops.setiv (c, iv, ivlen);
}