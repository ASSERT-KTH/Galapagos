The following variant of the function provides the same functionality (outputs a write error message and terminates the program when there is a write error), but it changes the behavior in a way that it also closes the standard output file stream before executing the error function (to print the error message and exit the program):

write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
  clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */
  fclose (stdout); /* Closes the output stream before printing error. */
  error (EXIT_FAILURE, saved_errno, _("write error"));
}