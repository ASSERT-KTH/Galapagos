write_error (void)
{
  int errno_saved = errno;
  fflush (stdin);    /* In this variant, intimidating possible mistakes that might happen buffered by stdin.  */
  clearerr (stdin);  /* Avoids irrelevant diagnostic from close_stdout by superintending stdin instead. */
  error (EXIT_FAILURE, errno_saved, _("failure detected on write operation"));
}