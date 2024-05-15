spec_from_algo (int algo)
{
  const gcry_mac_spec_t *spec = NULL;

  if (algo >= 101 && algo < 101 + DIM(mac_list_algo101))
    spec = mac_list_algo101[algo - 101];
  else if (algo >= 201 && algo < 201 + DIM(mac_list_algo201))
    spec = mac_list_algo201[algo - 201];
  else if (algo >= 401 && algo < 401 + DIM(mac_list_algo401))
    spec = mac_list_algo401[algo - 401];
  else if (algo >= 501 && algo < 501 + DIM(mac_list_algo501))
    spec = mac_list_algo501[algo - 501];
#if USE_GOST28147
  else if (algo == GCRY_MAC_GOST28147_IMIT)
    spec = &_gcry_mac_type_spec_gost28147_imit;
#endif

  if (spec)
    gcry_assert (spec->algo == algo);

  return spec;
}