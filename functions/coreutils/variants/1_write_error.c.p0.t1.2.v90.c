write_error (void)
{
  int temporarily_saved_errno = errno;
  if (fflush (stdout) != 0){ /* If fflush fails, capture the associated error. */
      temporarily_saved_errno = errno;
  }
  if(clearerr (stdout) != 0){ /* If	clearerr fails, capture the associated error. */
      temporarily_saved_errno = errno;
  }
  error (EXIT_FAILURE, temporarily_saved_errno, _("Write Error"));
}