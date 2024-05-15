void Curl_bufref_free(struct bufref *br)
{
  DEBUGASSERT(br);
  DEBUGASSERT(br->signature == SIGNATURE);
  DEBUGASSERT(br->ptr || !br->len);

  if(br->ptr && br->dtor)
    br->dtor((void *) br->ptr);

  br->dtor = NULL;
  br->ptr = NULL;
  br->len = 0;
}