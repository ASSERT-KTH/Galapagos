The following program variant maintains the original functionality but does also include additional behavior of checking errno before saving it.


write_error (void)
{
  int saved_errno;
  
  if (errno != 0) {
    saved_errno = errno;
  } else {
    saved_errno = EXIT_SUCCESS;
  }

  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  
  if (saved_errno != EXIT_SUCCESS) {
    error (EXIT_FAILURE, saved_errno, _("write error"));
  } else {
    error (EXIT_SUCCESS, saved_errno, _("no error"));
  }
}

This variant performs an additional consensus check before writing an error. This check won't affect an original expectation of reacting promptly on an occurred (errno-regstered) error. But will also segregate overall success (confirmed by errno's nullity) proclaimed as an 'opposite' to the write error.