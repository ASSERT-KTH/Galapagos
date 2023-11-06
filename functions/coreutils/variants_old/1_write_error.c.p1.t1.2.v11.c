Here's a variant of the write_error function. It has the same functionality but changes the actions' sequence. It first clears any error on stdout, then it ensures nothing is buffered that could produce an error, and finally it checks for an error using the previously saved errno.


write_error (void)
{
  int saved_errno = errno;
  clearerr (stdout);  /* Clear any existing errors */
  fflush (stdout);    /* Make sure nothing is buffered that might cause an error */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}


This reorder does not practically change behavior because `fflush` does not set `errno` when an error occurs, and `clearerr` just clears errors flags, it does not test and respond to any errors. Maintains it functionality might be ambiguous though, every trivial change changes a functions behavior in some form. Both works as long as `errno` originates from an stdio function. But correct `errno` processing manner is calling *`perror(3)`*, *`error(3)`*, or a similar function immediately after the failure giving orgin to `errno`:



write_error (void)
{
  error (EXIT_FAILURE, errno, _("write error"));
  fflush (stdout);    /* Not needed when exiting */
  clearerr (stdout);  /* Even less when exiting */
  ...      /* else we may overwrite errno here */
}
