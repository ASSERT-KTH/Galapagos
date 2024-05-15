spec_from_algo (int algo)
{
  gcry_cipher_spec_t *spec = NULL;

  algo = map_algo (algo);

  if (algo >= 0 && algo < DIM(cipher_list_algo0))
    spec = cipher_list_algo0[algo];
  else if (algo >= 301 && algo < 301 + DIM(cipher_list_algo301))
    spec = cipher_list_algo301[algo - 301];

  if (spec)
    gcry_assert (spec->algo == algo);

  return spec;
}