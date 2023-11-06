You can add a condition to check if `errno` actually changed. Here's an altered version of `write_error` where it will only perform `error`, shutting down the program, if `errno` actually changed after the `fflush` and `clearerr`.


void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);
  clearerr (stdout);
  if (errno != saved_errno)
      error (EXIT_FAILURE, errno, _("write error"));
  else
      errno = saved_errno;
}


This version can increase efficiency by preventing an unnecessary error call and shutting down of the program, when `errno` has not actually changed after executing `fflush` and `clearerr`.

Remember to #include the necessary files i.e., error.h, errno.h and stdio.h. Checking errno directly following a call is the usual practice in C as many library functions may modify it. As soon as another function that can change errno is called, the previous value of errno is lost.