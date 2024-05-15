test_keys (mpi_ec_t ec, unsigned int nbits)
{
  gcry_mpi_t test = mpi_new (nbits);
  mpi_point_struct R_;
  gcry_mpi_t c = mpi_new (nbits);
  gcry_mpi_t out = mpi_new (nbits);
  gcry_mpi_t r = mpi_new (nbits);
  gcry_mpi_t s = mpi_new (nbits);

  if (DBG_CIPHER)
    log_debug ("Testing key.\n");

  point_init (&R_);

  _gcry_mpi_randomize (test, nbits, GCRY_WEAK_RANDOM);

  if (_gcry_ecc_ecdsa_sign (test, NULL, ec, r, s, 0, 0) )
    log_fatal ("ECDSA operation: sign failed\n");

  if (_gcry_ecc_ecdsa_verify (test, ec, r, s, 0, 0))
    {
      log_fatal ("ECDSA operation: sign, verify failed\n");
    }

  if (DBG_CIPHER)
    log_debug ("ECDSA operation: sign, verify ok.\n");

  point_free (&R_);
  mpi_free (s);
  mpi_free (r);
  mpi_free (out);
  mpi_free (c);
  mpi_free (test);
}