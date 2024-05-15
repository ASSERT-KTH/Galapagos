spec_from_algo (int algo)
{
  int idx;
  gcry_pk_spec_t *spec;

  algo = map_algo (algo);

  for (idx = 0; (spec = pubkey_list[idx]); idx++)
    if (algo == spec->algo)
      return spec;
  return NULL;
}