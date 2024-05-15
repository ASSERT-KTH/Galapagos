spec_from_algo (int algo)
{
  const gcry_md_spec_t *spec = NULL;

  algo = map_algo (algo);

  if (algo >= 0 && algo < DIM(digest_list_algo0))
    spec = digest_list_algo0[algo];
  else if (algo >= 301 && algo < 301 + DIM(digest_list_algo301))
    spec = digest_list_algo301[algo - 301];

  if (spec)
    gcry_assert (spec->algo == algo);

  return spec;
}