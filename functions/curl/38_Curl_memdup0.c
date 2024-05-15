void *Curl_memdup0(const char *src, size_t length)
{
  char *buf = malloc(length + 1);
  if(!buf)
    return NULL;
  memcpy(buf, src, length);
  buf[length] = 0;
  return buf;
}