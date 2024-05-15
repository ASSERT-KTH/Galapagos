static void log_line_start(FILE *log, const char *timebuf,
                           const char *idsbuf, curl_infotype type)
{
  /*
   * This is the trace look that is similar to what libcurl makes on its
   * own.
   */
  static const char * const s_infotype[] = {
    "* ", "< ", "> ", "{ ", "} ", "{ ", "} "
  };
  if((timebuf && *timebuf) || (idsbuf && *idsbuf))
    fprintf(log, "%s%s%s", timebuf, idsbuf, s_infotype[type]);
  else
    fputs(s_infotype[type], log);
}