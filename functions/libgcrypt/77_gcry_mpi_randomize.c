gcry_mpi_randomize (gcry_mpi_t w,
                    unsigned int nbits, enum gcry_random_level level)
{
  if (!fips_is_operational ())
    {
      (void)fips_not_operational ();
      fips_signal_fatal_error ("called in non-operational state");
      fips_noreturn ();
    }

  _gcry_mpi_randomize (w, nbits, level);
}