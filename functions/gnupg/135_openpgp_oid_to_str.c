openpgp_oid_to_str (gcry_mpi_t a)
{
  const unsigned char *buf;
  unsigned int lengthi;

  if (!a
      || !gcry_mpi_get_flag (a, GCRYMPI_FLAG_OPAQUE)
      || !(buf = gcry_mpi_get_opaque (a, &lengthi)))
    {
      gpg_err_set_errno (EINVAL);
      return NULL;
    }

  return openpgp_oidbuf_to_str (buf, (lengthi+7)/8);
}