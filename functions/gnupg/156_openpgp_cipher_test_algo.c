openpgp_cipher_test_algo (cipher_algo_t algo)
{
  enum gcry_cipher_algos ga;

  ga = map_cipher_openpgp_to_gcry (algo);
  if (!ga)
    return gpg_error (GPG_ERR_CIPHER_ALGO);

  return gcry_cipher_test_algo (ga);
}