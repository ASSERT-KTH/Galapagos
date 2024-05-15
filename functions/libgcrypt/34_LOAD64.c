LOAD64(const mpi_ptr_t x, unsigned int pos)
{
  mpi_limb64_t v;
  v.lo = x[pos * 2 + 0];
  v.hi = x[pos * 2 + 1];
  return v;
}