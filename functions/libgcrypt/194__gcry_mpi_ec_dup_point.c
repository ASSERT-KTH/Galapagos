_gcry_mpi_ec_dup_point (mpi_point_t result, mpi_point_t point, mpi_ec_t ctx)
{
  switch (ctx->model)
    {
    case MPI_EC_WEIERSTRASS:
      dup_point_weierstrass (result, point, ctx);
      break;
    case MPI_EC_MONTGOMERY:
      dup_point_montgomery (result, point, ctx);
      break;
    case MPI_EC_EDWARDS:
      dup_point_edwards (result, point, ctx);
      break;
    }
}