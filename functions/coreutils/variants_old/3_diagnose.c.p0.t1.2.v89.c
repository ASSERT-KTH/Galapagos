diagnose (int errnum, char const *fmt, ...)
{
   if (progress_len > 0)
   {
      fprintf(stderr, "\n");
      progress_len = 0;
   }

   va_list arg_p;
   va_start (arg_p, fmt);
   verror (0, errnum, fmt, arg_p);
   va_end (arg_p);
}