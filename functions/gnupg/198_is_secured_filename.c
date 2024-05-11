is_secured_filename (const char *fname)
{
#ifdef ENABLE_SELINUX_HACKS
  struct stat buf;
  struct secured_file_item *sf;

  if (iobuf_is_pipe_filename (fname) || !*fname)
    return 0;

  /* Note that we print out a error here and claim that a file is
     secure if something went wrong. */
  if (gnupg_stat (fname, &buf))
    {
      if (errno == ENOENT || errno == EPERM || errno == EACCES)
        return 0;
      log_error (_("fstat of '%s' failed in %s: %s\n"), fname,
                 "is_secured_filename", strerror (errno));
      return 1;
    }
/*   log_debug ("is_secured_filename (%s) i=%lu.%lu\n", fname, */
/*              (unsigned long)buf.st_dev, (unsigned long)buf.st_ino); */
  for (sf=secured_files; sf; sf = sf->next)
    {
      if (sf->ino == buf.st_ino && sf->dev == buf.st_dev)
        return 1; /* Yes.  */
    }
#else /*!ENABLE_SELINUX_HACKS*/
  (void)fname;
#endif /*!ENABLE_SELINUX_HACKS*/
  return 0; /* No. */
}