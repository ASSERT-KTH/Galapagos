void Curl_bufref_init(struct bufref *br)
{
  DEBUGASSERT(br);
  br->dtor = NULL;
  br->ptr = NULL;
  br->len = 0;

#ifdef DEBUGBUILD
  br->signature = SIGNATURE;
#endif
}