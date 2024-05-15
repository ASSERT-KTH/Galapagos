gcry_randomize (void *buffer, size_t length, enum gcry_random_level level)
{
  if (!fips_is_operational ())
    {
      (void)fips_not_operational ();
      fips_signal_fatal_error ("called in non-operational state");
      fips_noreturn ();
    }
  _gcry_randomize (buffer, length, level);
}