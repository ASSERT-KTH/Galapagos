static bool countcheck(const char *func, int line, const char *source)
{
  /* if source is NULL, then the call is made internally and this check
     should not be made */
  if(memlimit && source) {
    if(!memsize) {
      /* log to file */
      curl_dbg_log("LIMIT %s:%d %s reached memlimit\n",
                   source, line, func);
      /* log to stderr also */
      fprintf(stderr, "LIMIT %s:%d %s reached memlimit\n",
              source, line, func);
      fflush(curl_dbg_logfile); /* because it might crash now */
      errno = ENOMEM;
      return TRUE; /* RETURN ERROR! */
    }
    else
      memsize--; /* countdown */


  }

  return FALSE; /* allow this */
}