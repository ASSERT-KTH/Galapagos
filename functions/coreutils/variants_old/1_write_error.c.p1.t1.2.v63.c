void write_error (void)
{
  int saved_errno = errno;
  fflush (stdout);    /* Ensure any buffered data are printed. */
  clearerr (stdout);  /* Clear any error flags before handling the error message. */

  if (saved_errno == 0) {
    /* If the error code is 0, it implies success, and doesn't produce an error. Exit successfully. */
    exit(EXIT_SUCCESS);
  } else {
    /* If the error code is not 0, it means an error has happened. Print the error message using the errno, and terminate the process. */
    perror(strerror(saved_errno));
    exit(EXIT_FAILURE);
  }
}