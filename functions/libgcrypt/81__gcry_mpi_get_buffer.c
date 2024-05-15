_gcry_mpi_get_buffer (gcry_mpi_t a, unsigned int fill_le,
                      unsigned int *r_nbytes, int *sign)
{
  if (mpi_get_flag (a, GCRYMPI_FLAG_OPAQUE))
    {
      unsigned int nbits;
      byte *p = _gcry_mpi_get_opaque_copy (a, &nbits);

      if (r_nbytes)
        *r_nbytes = (nbits+7)/8;

      return p;
    }
  else
    return do_get_buffer (a, fill_le, 0, r_nbytes, sign, 0);
}