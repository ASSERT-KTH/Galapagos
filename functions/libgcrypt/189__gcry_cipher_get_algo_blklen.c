_gcry_cipher_get_algo_blklen (int algo)
{
  size_t n;

  if (_gcry_cipher_algo_info( algo, GCRYCTL_GET_BLKLEN, NULL, &n))
    n = 0;
  return n;
}