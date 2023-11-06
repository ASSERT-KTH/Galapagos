write_error(void)
{
  int savederror = errno;
  fflush(stdout);  /* To make sure nothing buffered that might induce an error. */
  clearerr(stdout);  /* To sidestep extra diagnostic from closing standard output. */
  error(EXIT_FAILURE, savederror, _("write error occurred"));
}