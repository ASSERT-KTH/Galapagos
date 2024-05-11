openpgp_oid_to_curve (const char *oidstr, int mode)
{
  int i;

  if (!oidstr)
    return NULL;

  for (i=0; oidtable[i].name; i++)
    if (!strcmp (oidtable[i].oidstr, oidstr))
      {
        if (mode == 2)
          {
            if (oidtable[i].abbr)
              return oidtable[i].abbr;
            mode = 0; /* No abbreviation - fallback to mode 0.  */
          }
        return !mode && oidtable[i].alias? oidtable[i].alias : oidtable[i].name;
      }

  return NULL;
}