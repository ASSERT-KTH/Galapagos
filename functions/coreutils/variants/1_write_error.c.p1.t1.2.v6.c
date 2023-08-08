write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  clearerr (stdout);

  switch(saved_errno)
  {
    /* maintain all prior functionality */
    case 0:
      error (EXIT_FAILURE, saved_errno, _("write error"));
      break;

    default:
      /* add additional control but maintain the original functionality when none of these are matched */
      error (EXIT_FAILURE, saved_errno, _("write error"));
      break;
  }
}