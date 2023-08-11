void write_error(void)
{
  int error_state = errno; /* Renames 'saved_errno' variable to 'error_state'. */

  fflush(stdout); /* As in the original function, this makes sure there are no unwritten output in 'stdout'. */
  
  clearerr(stdout); /* Tries to clear any error status for 'stdout'. */
  
  /* At last, remaining procedure as it was in the original function. */
  error(EXIT_FAILURE, error_state, _("write error"));
}