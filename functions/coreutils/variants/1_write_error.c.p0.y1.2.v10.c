void write_error()
{
  int error_saved = errno; // Save the errno value.
  fflush(stdout);          // Flashing stdout to prevent further errors
  clearerr(stdout);        // Prevent output error on stdout

  /* Calling error. EXIT_FAILURE = non-zero(1); error is an Inbuilt error-reporting API from error.h */
  error(1, error_saved, "write error");
}