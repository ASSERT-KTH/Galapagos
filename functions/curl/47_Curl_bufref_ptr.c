const unsigned char *Curl_bufref_ptr(const struct bufref *br)
{
  DEBUGASSERT(br);
  DEBUGASSERT(br->signature == SIGNATURE);
  DEBUGASSERT(br->ptr || !br->len);

  return br->ptr;
}