gcry_create_nonce (void *buffer, size_t length)
{
  if (!fips_is_operational ())
    {
      (void)fips_not_operational ();
      fips_signal_fatal_error ("called in non-operational state");
      fips_noreturn ();
    }
  _gcry_create_nonce (buffer, length);
}