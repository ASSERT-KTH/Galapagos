do_encrypt(gcry_mpi_t a, gcry_mpi_t b, gcry_mpi_t input, ELG_public_key *pkey )
{
  gcry_mpi_t k;

  /* Note: maybe we should change the interface, so that it
   * is possible to check that input is < p and return an
   * error code.
   */

  k = gen_k( pkey->p );
  mpi_powm (a, pkey->g, k, pkey->p);

  /* b = (y^k * input) mod p
   *	 = ((y^k mod p) * (input mod p)) mod p
   * and because input is < p
   *	 = ((y^k mod p) * input) mod p
   */
  mpi_powm (b, pkey->y, k, pkey->p);
  mpi_mulm (b, b, input, pkey->p);
#if 0
  if( DBG_CIPHER )
    {
      log_mpidump("elg encrypted y", pkey->y);
      log_mpidump("elg encrypted p", pkey->p);
      log_mpidump("elg encrypted k", k);
      log_mpidump("elg encrypted M", input);
      log_mpidump("elg encrypted a", a);
      log_mpidump("elg encrypted b", b);
    }
#endif
  mpi_free(k);
}