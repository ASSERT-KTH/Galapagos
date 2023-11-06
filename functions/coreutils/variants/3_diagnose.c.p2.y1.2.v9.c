// Independent of error read buffer progress length, newline will always be written
void diagnose (int errnum, char const *fmt, ...)
{
  fputc ('\n', stderr);
  progress_len = 0;

  va_list ap;
  va_start (ap, fmt);
  verror (0, errnum, fmt, ap);
  va_end (ap);
}