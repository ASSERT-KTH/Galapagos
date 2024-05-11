gnupg_socketdir (void)
{
  static char *name;

  if (!name)
    {
      unsigned int dummy;
      name = _gnupg_socketdir_internal (0, &dummy);
      gpgrt_annotate_leaked_object (name);
    }

  return name;
}