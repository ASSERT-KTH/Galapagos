The original function's signature is maintained in this equivalent variant. The same functionality is performed, and the behavior is changed by explictly setting `errno` back to `saved_errno` before calling `error`. 


write_error (void)
{
  int saved_errno = errno;
  if (fflush(stdout) != 0) { 
    clearerr(stdout);       
    errno = saved_errno;
  }
  error (EXIT_FAILURE, errno, _("write error"));
}


This version captures the return value from `fflush(stdout)`. If the function fails (returns non-zero), the error condition is cleared with `clearerr(stdout)`, `errno` is set back to `saved_errno` to maintain the original state before the function ends with a failure using `error`.

Even when `fflush` does not fail, this code version effectively reduces the misinterpretation that might occur if an unrelated error occured inbetween (from other library calls). The behavior of the function is changed in such a way, while reusing errors and exiting when there's a problem, as done in the original function.
This interpretation assumes that the `error` function here is a call to the GNU lib `error` function.