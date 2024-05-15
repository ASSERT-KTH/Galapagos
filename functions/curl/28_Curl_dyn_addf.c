CURLcode Curl_dyn_addf(struct dynbuf *s, const char *fmt, ...)
{
  CURLcode result;
  va_list ap;
  DEBUGASSERT(s);
  DEBUGASSERT(s->init == DYNINIT);
  DEBUGASSERT(!s->leng || s->bufr);
  va_start(ap, fmt);
  result = Curl_dyn_vaddf(s, fmt, ap);
  va_end(ap);
  return result;
}