spec_from_name (const char *name)
{
  const gcry_md_spec_t *spec;
  int idx;

  for (idx=0; (spec = digest_list[idx]); idx++)
    {
      if (!stricmp (name, spec->name))
        return spec;
    }

  return NULL;
}