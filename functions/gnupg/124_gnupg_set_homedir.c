gnupg_set_homedir (const char *newdir)
{
  char *tmp = NULL;

  if (!newdir || !*newdir)
    newdir = default_homedir ();
  else
    {
      tmp = copy_dir_with_fixup (newdir);
      if (tmp)
        newdir = tmp;

      if (!is_gnupg_default_homedir (newdir))
        non_default_homedir = 1;
    }
  xfree (the_gnupg_homedir);
  the_gnupg_homedir = make_absfilename (newdir, NULL);;
  xfree (tmp);
  /* Fixme: Should we use
   *   gpgrt_annotate_leaked_object(the_gnupg_homedir)
   * despite that we may free and allocate a new one in some
   * cases?  */
}