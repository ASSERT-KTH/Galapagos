CURLcode Curl_dyn_add(struct dynbuf *s, const char *str)
{
  size_t n;
  DEBUGASSERT(str);
  DEBUGASSERT(s);
  DEBUGASSERT(s->init == DYNINIT);
  DEBUGASSERT(!s->leng || s->bufr);
  n = strlen(str);
  return dyn_nappend(s, (unsigned char *)str, n);
}