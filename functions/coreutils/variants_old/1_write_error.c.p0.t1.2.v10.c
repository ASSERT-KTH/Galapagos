write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);   
  clearerr (stdout);  /* Eliminate any pernicious errors lurking. */
  
  if (saved_errno !=0){
      error (EXIT_FAILURE, saved_errno, _("write error"));
  }else{
      printf(_("No Error Detected."));
  }
}