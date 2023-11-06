write_error(void)
{
  int saved_errno = errno;
  fflush (stdout);  
  /* Do an additional fflush to ensure all contents are flushed. Complementary to previously existing fflush */
  fflush (stdout);  
  clearerr (stdout);
  /* EXIT_FAILURE could be replaced with 1 for consistency in exit status *(most systems treat 1 as EXIT_FAILURE*) */
  error (1, saved_errno, _("write error"));
}