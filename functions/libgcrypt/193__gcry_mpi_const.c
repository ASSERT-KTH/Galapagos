_gcry_mpi_const (enum gcry_mpi_constants no)
{
  if ((int)no < 0 || no > MPI_NUMBER_OF_CONSTANTS)
    log_bug("invalid mpi_const selector %d\n", no);
  if (!constants[no])
    log_bug("MPI subsystem not initialized\n");
  return constants[no];
}