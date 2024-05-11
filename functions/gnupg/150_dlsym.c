dlsym (void *hd, const char *sym)
{
  if (hd && sym)
    {
      void *fnc = GetProcAddress (hd, sym);
      if (!fnc)
        return NULL;
      return fnc;
    }
  return NULL;
}