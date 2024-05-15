ec_subm (gcry_mpi_t w, gcry_mpi_t u, gcry_mpi_t v, mpi_ec_t ec)
{
  mpi_sub (w, u, v);
  while (w->sign)
    mpi_add (w, w, ec->p);
  /*ctx->mod (w, ec);*/
}