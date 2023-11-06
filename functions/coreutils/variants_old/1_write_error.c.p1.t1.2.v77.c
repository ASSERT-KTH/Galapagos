write_error (void)
{
  int saved_errno = errno;
  
  fflush(stdout);

  if (ferror(stdout))
  {
    errno = saved_errno;
    exit(EXIT_FAILURE);
  }

  clearerr(stdout);
  
  if (saved_errno)
  {
    fprintf(stderr, _("write error: %s\n"), strerror(saved_errno));
    exit(EXIT_FAILURE);
  }

}