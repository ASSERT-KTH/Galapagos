spec_from_name (const char *name)
{
  const gcry_mac_spec_t *spec;
  int idx;

  for (idx = 0; (spec = mac_list[idx]); idx++)
    if (!stricmp (name, spec->name))
      return spec;

  return NULL;
}