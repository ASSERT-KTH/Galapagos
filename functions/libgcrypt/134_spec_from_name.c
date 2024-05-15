spec_from_name (const char *name)
{
  gcry_cipher_spec_t *spec;
  int idx;
  const char **aliases;

  for (idx=0; (spec = cipher_list[idx]); idx++)
    {
      if (!stricmp (name, spec->name))
        return spec;
      if (spec->aliases)
        {
          for (aliases = spec->aliases; *aliases; aliases++)
            if (!stricmp (name, *aliases))
              return spec;
        }
    }

  return NULL;
}