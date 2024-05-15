ec_invm (gcry_mpi_t x, gcry_mpi_t a, mpi_ec_t ctx)
{
  if (!mpi_invm (x, a, ctx->p))
    {
      log_error ("ec_invm: inverse does not exist:\n");
      log_mpidump ("  a", a);
      log_mpidump ("  p", ctx->p);
    }
}