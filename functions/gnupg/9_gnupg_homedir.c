gnupg_homedir (void)
{
  /* If a homedir has not been set, set it to the default.  */
  if (!the_gnupg_homedir)
    the_gnupg_homedir = make_absfilename (default_homedir (), NULL);
  return the_gnupg_homedir;
}