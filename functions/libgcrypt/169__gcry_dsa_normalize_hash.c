_gcry_dsa_normalize_hash (gcry_mpi_t input,
                          gcry_mpi_t *out,
                          unsigned int qbits)
{
  gpg_err_code_t rc = 0;
  const void *abuf;
  unsigned int abits;
  gcry_mpi_t hash;

  if (mpi_is_opaque (input))
    {
      abuf = mpi_get_opaque (input, &abits);
      rc = _gcry_mpi_scan (&hash, GCRYMPI_FMT_USG, abuf, (abits+7)/8, NULL);
      if (rc)
        return rc;
      if (abits > qbits)
        mpi_rshift (hash, hash, abits - qbits);
    }
  else
    hash = input;

  *out = hash;

  return rc;
}