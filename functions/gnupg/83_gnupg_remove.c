gnupg_remove (const char *fname)
{
#ifdef HAVE_W32_SYSTEM
  int rc;
  wchar_t *wfname;

  wfname = utf8_to_wchar (fname);
  if (!wfname)
    rc = 0;
  else
    {
      rc = DeleteFileW (wfname);
      if (!rc)
        gnupg_w32_set_errno (-1);
      xfree (wfname);
    }
  if (!rc)
    return -1;
  return 0;
#else
  /* It is common to use /dev/null for testing.  We better don't
   * remove that file.  */
  if (fname && !strcmp (fname, "/dev/null"))
    return 0;
  else
    return remove (fname);
#endif
}