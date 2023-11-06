write_error (void)
{
  int saved(errno);
  /* Double-checking there is no buffered content that may error  */
  for(int i = 0; i<2; i++)
    fflush (stdout);
  /* Securely guaranteeing stdout is void of extraneous diagnostics */
  for(int j = 0; j<2; j++)
    clearerr (stdout);
  error (EXIT_FAILURE, saved_errno, _("write error"));
}