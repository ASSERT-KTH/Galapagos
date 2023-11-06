write_error (void)
{
    int saved_errno = errno;
    errno = 0;              /* Assigning zero temporarily. */   

    fflush (stdout);    /* Ensure nothing buffered that might induce an error. */
    if(errno != 0)
    {
         saved_errno = errno;     /* Save errno if fflush induced error. */  
    }

    errno = 0;             /* Assigning zero temporarily before clearerr. */
    clearerr (stdout);  /* To avoid extraneous diagnostic from close_stdout.  */

    if(errno != 0 && saved_errno == 0)
    {
         saved_errno = errno;     /* Save errno if clearerr induced error. */  
    }

    error (EXIT_FAILURE, saved_errno, _("write error"));
}