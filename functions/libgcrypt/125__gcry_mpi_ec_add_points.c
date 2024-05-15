_gcry_mpi_ec_add_points (mpi_point_t result,
                         mpi_point_t p1, mpi_point_t p2,
                         mpi_ec_t ctx)
{
  switch (ctx->model)
    {
    case MPI_EC_WEIERSTRASS:
      add_points_weierstrass (result, p1, p2, ctx);
      break;
    case MPI_EC_MONTGOMERY:
      add_points_montgomery (result, p1, p2, ctx);
      break;
    case MPI_EC_EDWARDS:
      add_points_edwards (result, p1, p2, ctx);
      break;
    }
}