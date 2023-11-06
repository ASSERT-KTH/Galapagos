void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t result = fwrite (buffer, 1, n_bytes, stdout);
  if (n_bytes > 0 && result < n_bytes)
  {
      fflush(stdout);
      error (EXIT_FAILURE, errno, _("Problem occurred while writing %s"),
             quote ("standard output"));
      fclose(stdout);
  }
}