CURLcode Curl_dyn_tail(struct dynbuf *s, size_t trail)
{
  DEBUGASSERT(s);
  DEBUGASSERT(s->init == DYNINIT);
  DEBUGASSERT(!s->leng || s->bufr);
  if(trail > s->leng)
    return CURLE_BAD_FUNCTION_ARGUMENT;
  else if(trail == s->leng)
    return CURLE_OK;
  else if(!trail) {
    Curl_dyn_reset(s);
  }
  else {
    memmove(&s->bufr[0], &s->bufr[s->leng - trail], trail);
    s->leng = trail;
    s->bufr[s->leng] = 0;
  }
  return CURLE_OK;

}