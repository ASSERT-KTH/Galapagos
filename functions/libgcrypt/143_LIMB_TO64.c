LIMB_TO64(mpi_limb_t x)
{
  mpi_limb64_t v;
  v.lo = x;
  v.hi = 0;
  return v;
}