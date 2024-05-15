void curl_dbg_log(const char *format, ...)
{
  char *buf;
  int nchars;
  va_list ap;

  if(!curl_dbg_logfile)
    return;

  buf = (Curl_cmalloc)(LOGLINE_BUFSIZE);
  if(!buf)
    return;

  va_start(ap, format);
  nchars = mvsnprintf(buf, LOGLINE_BUFSIZE, format, ap);
  va_end(ap);

  if(nchars > LOGLINE_BUFSIZE - 1)
    nchars = LOGLINE_BUFSIZE - 1;

  if(nchars > 0)
    fwrite(buf, 1, (size_t)nchars, curl_dbg_logfile);

  (Curl_cfree)(buf);
}