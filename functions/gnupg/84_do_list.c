do_list (int is_error, int listmode, estream_t fp, const char *format, ...)
{
  va_list arg_ptr;

  va_start (arg_ptr, format) ;
  if (listmode)
    {
      if (fp)
        {
          es_fputs ("  [", fp);
          es_vfprintf (fp, format, arg_ptr);
          es_fputs ("]\n", fp);
        }
    }
  else
    {
      es_fflush (es_stdout);
      log_logv (is_error? GPGRT_LOGLVL_ERROR: GPGRT_LOGLVL_INFO,
                format, arg_ptr);
      log_printf ("\n");
    }
  va_end (arg_ptr);
}