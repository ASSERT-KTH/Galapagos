_gcry_mpi_ec_ec2os (gcry_mpi_point_t point, mpi_ec_t ec)
{
  gcry_mpi_t g_x, g_y, result;

  g_x = mpi_new (0);
  g_y = mpi_new (0);
  if (_gcry_mpi_ec_get_affine (g_x, g_y, point, ec))
    result = NULL;
  else
    result = _gcry_ecc_ec2os (g_x, g_y, ec->p);
  mpi_free (g_x);
  mpi_free (g_y);

  return result;
}