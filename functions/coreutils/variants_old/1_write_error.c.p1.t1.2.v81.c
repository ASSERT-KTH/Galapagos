Sure, a possible variant can expand on error handling by checking if the `fflush()` or `clearerr()` function calls fail. Here is a variant that maintains original functionality:


write_error (void)
{
  int saved_errno = errno;
  
  if (fflush (stdout) != 0) { /* fflush might induce an error */
    error (EXIT_FAILURE, errno, _("fflush error before write error"));
    return;
  }
  if (ferror(stdout)) {      /* If a previous I/O operation resulted in error */
    clearerr(stdout);
    if (ferror(stdout)) {    /* Checking after clearerr */
        error(EXIT_FAILURE, errno, _("stdout error in clearerr before write error"));
        return;
    }
  }
  error (EXIT_FAILURE, saved_errno, _("write error"));
}



Take note that the errno value is very likely to change as it monitors global errors per thread that could occur from low-level operations happening behind the scenes even within C standard library function implementations. Therefore, the errno value used by the function error(), could be something completely different by the time that line is actually executed depending on trade-offs between high-level control of program data flow and low-level events occurring in CPU/s consequently it's sometimes hard to get the errno that directly relates to the custom errors you want to handle. As a workaround and on best efforts ground, we saved the errno as soon as entered in our function before other potential error-modifying operations can run.