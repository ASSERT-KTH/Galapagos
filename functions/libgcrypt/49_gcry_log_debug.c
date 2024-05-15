gcry_log_debug (const char *fmt, ...)
{
  va_list arg_ptr ;

  va_start( arg_ptr, fmt ) ;
  _gcry_logv (GCRY_LOG_DEBUG, fmt, arg_ptr);
  va_end (arg_ptr);
}