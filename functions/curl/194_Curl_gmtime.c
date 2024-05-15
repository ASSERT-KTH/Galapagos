CURLcode Curl_gmtime(time_t intime, struct tm *store)
{
  const struct tm *tm;
#ifdef HAVE_GMTIME_R
  /* thread-safe version */
  tm = (struct tm *)gmtime_r(&intime, store);
#else
  /* !checksrc! disable BANNEDFUNC 1 */
  tm = gmtime(&intime);
  if(tm)
    *store = *tm; /* copy the pointed struct to the local copy */
#endif

  if(!tm)
    return CURLE_BAD_FUNCTION_ARGUMENT;
  return CURLE_OK;
}