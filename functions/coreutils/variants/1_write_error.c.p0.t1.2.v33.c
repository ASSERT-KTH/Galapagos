write_error (void)
{
   int saved_errno = errno;
   errno = 0;
   fflush (stdout);
 
   if (errno == 0)
   { 
      errno = saved_errno; 
   }
   
   clearerr (stdout);
   error (EXIT_FAILURE, errno, _("write error"));
}