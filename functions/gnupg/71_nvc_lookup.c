nvc_lookup (nvc_t pk, const char *name)
{
  nve_t entry;

  if (!pk)
    return NULL;

  for (entry = pk->first; entry; entry = entry->next)
    if (entry->name && ascii_strcasecmp (entry->name, name) == 0)
      return entry;

  return NULL;
}