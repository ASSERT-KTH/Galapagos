gnupg_sysconfdir (void)
{
#ifdef HAVE_W32_SYSTEM
  static char *name;

  if (!name)
    {
      name = xstrconcat (w32_commondir (), DIRSEP_S, "etc", DIRSEP_S,
                         my_gnupg_dirname (), NULL);
      gpgrt_annotate_leaked_object (name);
    }
  return name;
#else /*!HAVE_W32_SYSTEM*/
  const char *dir = unix_rootdir (WANTDIR_SYSCONF);
  if (dir)
    return dir;
  else
    return GNUPG_SYSCONFDIR;
#endif /*!HAVE_W32_SYSTEM*/
}