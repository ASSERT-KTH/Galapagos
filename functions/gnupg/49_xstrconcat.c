xstrconcat (const char *s1, ...)
{
  va_list arg_ptr;
  char *result;

  if (!s1)
    result = xstrdup ("");
  else
    {
      va_start (arg_ptr, s1);
      result = vstrconcat (s1, arg_ptr);
      va_end (arg_ptr);
    }
  if (!result)
    {
      if (errno == EINVAL)
        fputs ("\nfatal: too many args for xstrconcat\n", stderr);
      else
        fputs ("\nfatal: out of memory\n", stderr);
      exit (2);
    }
  return result;
}