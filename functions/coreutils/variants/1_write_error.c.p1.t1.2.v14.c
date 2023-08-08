write_error (void)
{
  int saved_err_no = errno;
  fflush (stdout);  
  clearerr (stdout);  

  if (saved_err_no != 0) {
    error (EXIT_FAILURE, saved_err_no, _("write error"));
  } else {
    puts(_("No write error occurred."));
  }
}