write_status (int no, const char *format, ...)
{
  va_list arg_ptr;

  if (!opt.statusfp)
    return;  /* Not enabled.  */

  es_fputs ("[GNUPG:] ", opt.statusfp);
  es_fputs (get_status_string (no), opt.statusfp);
  if (format)
    {
      es_putc (' ', opt.statusfp);
      va_start (arg_ptr, format);
      es_vfprintf (opt.statusfp, format, arg_ptr);
      va_end (arg_ptr);
    }
  es_putc ('\n', opt.statusfp);
}