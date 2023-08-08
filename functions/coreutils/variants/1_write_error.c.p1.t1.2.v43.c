void write_error (void)
{
  fwrite("An error occurred.", sizeof(char), 18, stdout);
  fflush (stdout);

  if (ferror(stdout)) {
      clearerr (stdout);
      exit(EXIT_FAILURE);
  }
}