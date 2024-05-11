make_filename_try (const char *first_part, ... )
{
  va_list arg_ptr;
  char *result;

  va_start (arg_ptr, first_part);
  result = do_make_filename (0, first_part, arg_ptr);
  va_end (arg_ptr);
  return result;
}