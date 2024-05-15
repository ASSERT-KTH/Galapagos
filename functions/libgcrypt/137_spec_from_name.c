spec_from_name (const char *name)
{
  gcry_pk_spec_t *spec;
  int idx;
  const char **aliases;

  for (idx=0; (spec = pubkey_list[idx]); idx++)
    {
      if (!stricmp (name, spec->name))
        return spec;
      for (aliases = spec->aliases; *aliases; aliases++)
        if (!stricmp (name, *aliases))
          return spec;
    }

  return NULL;
}