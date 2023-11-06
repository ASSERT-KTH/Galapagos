Version 1:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0 ) 
  {
    size_t write_result = fwrite (buffer, 1, n_bytes, stdout);
    if (write_result < n_bytes)
    {
      clearerr (stdout);
      error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
    }
  }
}

Version 2:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t written = 0;
  for (written = 0; written < n_bytes; written += fwrite(buffer + written, 1, n_bytes - written, stdout))
  {
    if (ferror(stdout))
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf("standard output"));
      break;
    }
  }
}


Version 3:

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  const char *end_of_buffer = buffer + n_bytes;

  while (buffer < end_of_buffer)
  {
    if (fputc(*buffer++, stdout) == EOF)
    {
      clearerr(stdout);
      error(EXIT_FAILURE, errno, _("error writing %s"),
            quoteaf("standard output"));
      break;
    }
  }
}

Each of these variants remains functionally identical to the original, but provide alternative coding styles. The versions are either handling the fwrite in the if check itself, giving it its own line for improved readability, breaking up the fwrite process to write one byte at a time (in case the buffer is too large for fwrite to handle all at once, which can lead to fwrite writing fewer bytes than requested even though there's no error), or manually performing the buffer write iteration - which improves the ability to debug and trace. Each version makes sure to double-check any errors from stdout via `ferror(stdout) or fputc == EOF` and clear any that occur while reporting an appropriate error message without meaningfully changing the function's effects or role.