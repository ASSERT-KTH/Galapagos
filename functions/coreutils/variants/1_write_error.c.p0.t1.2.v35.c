write_error_in_variant (void)
{
  int saved_errno = errno;
  fflush (stderr);     /* Ensure nothing buffered in stderr might induce an error. */
  clearerr (stderr);   /* To avoid extraneous diagnostic from stderr i/o operations. */
  error (EXIT_FAILURE, saved_errno, _("A writing error has occurred"));
}