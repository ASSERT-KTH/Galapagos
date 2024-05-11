strconcat (const char *s1, ...)
{
  va_list arg_ptr;
  char *result;

  if (!s1)
    result = xtrystrdup ("");
  else
    {
      va_start (arg_ptr, s1);
      result = vstrconcat (s1, arg_ptr);
      va_end (arg_ptr);
    }
  return result;
}