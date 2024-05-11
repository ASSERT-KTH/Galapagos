nbits_from_pk (PKT_public_key *pk)
{
  if (pk->pubkey_algo == PUBKEY_ALGO_KYBER)
    {
      unsigned int nbits;
      if (!gcry_mpi_get_opaque (pk->pkey[2], &nbits))
        return 0;
      switch (nbits/8)
        {
        case 800:  nbits =  512; break;
        case 1184: nbits =  768; break;
        case 1568: nbits = 1024; break;
        default:   nbits = 0;    break;  /* Unkown version.  */
        }
      return nbits;
    }
  else
    return pubkey_nbits (pk->pubkey_algo, pk->pkey);
}