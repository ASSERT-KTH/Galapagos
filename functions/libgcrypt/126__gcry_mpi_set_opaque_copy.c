_gcry_mpi_set_opaque_copy (gcry_mpi_t a, const void *p, unsigned int nbits)
{
  void *d;
  unsigned int n;

  n = (nbits+7)/8;
  d = _gcry_is_secure (p)? xtrymalloc_secure (n) : xtrymalloc (n);
  if (!d)
    return NULL;
  memcpy (d, p, n);
  return mpi_set_opaque (a, d, nbits);
}