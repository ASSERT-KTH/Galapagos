You can vary the behavior of the original function by tweaking the condition that triggers the fputc function. Also, adding an error logging string format for the function to handle multiple error types.

diagnose(int errnum, char const *fmt, ...)
{
  if (progress_len >= 1)
  {
    fputc('\n', stderr);
    progress_len = 0;
  }

  va_list ap;
  va_start(ap, fmt);

  char new_fmt[100];
  sprintf(new_fmt, "[ERROR NUMBER #%d] -->", errnum);

  int length = strlen(new_fmt);
  char *final_fmt = (char *)malloc(length+strlen(fmt)+1);

  if(!final_fmt) return;

  strcpy(final_fmt, new_fmt);
  strcat(final_fmt, fmt);

  verror(0, errnum, final_fmt, ap);

  va_end(ap);
}