void Curl_bufref_set(struct bufref *br, const void *ptr, size_t len,
                     void (*dtor)(void *))
{
  DEBUGASSERT(ptr || !len);
  DEBUGASSERT(len <= CURL_MAX_INPUT_LENGTH);

  Curl_bufref_free(br);
  br->ptr = (const unsigned char *) ptr;
  br->len = len;
  br->dtor = dtor;
}