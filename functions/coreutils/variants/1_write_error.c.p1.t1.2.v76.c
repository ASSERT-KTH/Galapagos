write_error (void)
{
   int saved_errno = errno;
   if(ferror(stdout)) /* Checks for an error in the output stream */
      perror(_("Error at stdout")); 
      
   fflush (stdout);  /* Ensure nothing buffered that might induce an error. */
   
   if(ferror(stdout))   /* Checks for an error again after fflush */
       perror(_("Error at fflush stdout"));

   clearerr (stdout);   /* To avoid extraneous diagnostic from close_stdout. */
   
   if(saved_errno == errno){    /* Checks that errno has not changed after all operations */
       error (EXIT_FAILURE, saved_errno, _("write error"));
   }
   else{
      error(EXIT_FAILURE, errno,_("write error and Errno value is changed")); 
  }
}