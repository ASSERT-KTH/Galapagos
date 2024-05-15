CURLcode Curl_dyn_addn(struct dynbuf *s, const void *mem, size_t len)
{
  DEBUGASSERT(s);
  DEBUGASSERT(s->init == DYNINIT);
  DEBUGASSERT(!s->leng || s->bufr);
  return dyn_nappend(s, mem, len);
}