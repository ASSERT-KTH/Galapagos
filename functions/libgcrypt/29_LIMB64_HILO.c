LIMB64_HILO(mpi_limb_t hi, mpi_limb_t lo)
{
  mpi_limb64_t v;
  v.lo = lo;
  v.hi = hi;
  return v;
}