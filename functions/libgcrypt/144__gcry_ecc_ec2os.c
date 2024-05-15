_gcry_ecc_ec2os (gcry_mpi_t x, gcry_mpi_t y, gcry_mpi_t p)
{
  unsigned char *buf;
  unsigned int buflen;

  buf = _gcry_ecc_ec2os_buf (x, y, p, &buflen);
  return mpi_set_opaque (NULL, buf, 8*buflen);
}