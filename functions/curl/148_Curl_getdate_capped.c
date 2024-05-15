time_t Curl_getdate_capped(const char *p)
{
  time_t parsed = -1;
  int rc = parsedate(p, &parsed);

  switch(rc) {
  case PARSEDATE_OK:
    if(parsed == -1)
      /* avoid returning -1 for a working scenario */
      parsed++;
    return parsed;
  case PARSEDATE_LATER:
    /* this returns the maximum time value */
    return parsed;
  default:
    return -1; /* everything else is fail */
  }
  /* UNREACHABLE */
}