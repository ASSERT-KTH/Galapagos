openpgp_md_test_algo (digest_algo_t algo)
{
  enum gcry_md_algos ga;

  ga = map_md_openpgp_to_gcry (algo);
  if (!ga)
    return gpg_error (GPG_ERR_DIGEST_ALGO);

  return gcry_md_test_algo (ga);
}