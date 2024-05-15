gcry_md_hash_buffer (int algo, void *digest,
                     const void *buffer, size_t length)
{
  if (!fips_is_operational ())
    {
      (void)fips_not_operational ();
      fips_signal_error ("called in non-operational state");
    }
  _gcry_md_hash_buffer (algo, digest, buffer, length);
}