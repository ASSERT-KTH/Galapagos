You can keep the functionality of the original function while changing its behavior by manipulating the sequence of statements in the function. In the modified function below, the function firstly clears any extraneous diagnostics, then ensures that the data in the buffer is written out to stdout before it saves errno. It changes the behavior but not the functionality of the original function.   

Here is the requested program variant:


write_error (void)
{
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout first.  */
  fflush (stdout);    /* Ensure nothing buffered that might induce an error afterwards. */
  int saved_errno = errno; /* save errno at the end */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}
