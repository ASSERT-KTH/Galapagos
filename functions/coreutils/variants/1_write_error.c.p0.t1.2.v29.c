write_error (void)
{
  int error_no = errno;
  fseek (stdout, 0, SEEK_END); /* Position end of stdout to avoid unexpected write position */
  clearerr (stdout);   /* Clearing stdout error flag */
  if(error_no != 0)    /* Checking if no error exists before calling error() */
     error (EXIT_FAILURE, error_no, _("write error"));
}