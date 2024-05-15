_gcry_mpi_randomize (gcry_mpi_t w,
                     unsigned int nbits, enum gcry_random_level level)
{
  unsigned char *p;
  size_t nbytes = (nbits+7)/8;

  if (mpi_is_immutable (w))
    {
      mpi_immutable_failed ();
      return;
    }
  if (level == GCRY_WEAK_RANDOM)
    {
      p = mpi_is_secure(w) ? xmalloc_secure (nbytes)
                           : xmalloc (nbytes);
      _gcry_create_nonce (p, nbytes);
    }
  else
    {
      p = mpi_is_secure(w) ? _gcry_random_bytes_secure (nbytes, level)
                           : _gcry_random_bytes (nbytes, level);
    }
  _gcry_mpi_set_buffer( w, p, nbytes, 0 );
  xfree (p);
}