is_secured_file (gnupg_fd_t fd)
{
#ifdef ENABLE_SELINUX_HACKS
  struct stat buf;
  struct secured_file_item *sf;

  if (fd == -1)
    return 0; /* No file descriptor so it can't be secured either.  */

  /* Note that we print out a error here and claim that a file is
     secure if something went wrong. */
  if (fstat (fd, &buf))
    {
      log_error (_("fstat(%d) failed in %s: %s\n"), fd,
                 "is_secured_file", strerror (errno));
      return 1;
    }
/*   log_debug ("is_secured_file (%d) i=%lu.%lu\n", fd, */
/*              (unsigned long)buf.st_dev, (unsigned long)buf.st_ino); */
  for (sf=secured_files; sf; sf = sf->next)
    {
      if (sf->ino == buf.st_ino && sf->dev == buf.st_dev)
        return 1; /* Yes.  */
    }
#else /*!ENABLE_SELINUX_HACKS*/
  (void)fd;
#endif /*!ENABLE_SELINUX_HACKS*/
  return 0; /* No. */
}