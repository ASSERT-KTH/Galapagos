_gcry_logv (int level, const char *fmt, va_list arg_ptr)
{
  if (log_handler)
    {
      /* The deprecated log handler has been registered.  */
      log_handler (log_handler_value, level, fmt, arg_ptr);
      if (level == GCRY_LOG_FATAL || level == GCRY_LOG_BUG)
        {
          fips_signal_fatal_error ("internal error (fatal or bug)"
                                   " [legacy bug handler]");
          _gcry_secmem_term ();
          abort ();
        }
    }
  else
    {
      gpgrt_logv_domain ("gcrypt", map_log_level (level), NULL, NULL, 0,
                         fmt, arg_ptr);
    }
}