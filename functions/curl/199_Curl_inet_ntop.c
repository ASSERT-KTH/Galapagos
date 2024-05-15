char *Curl_inet_ntop(int af, const void *src, char *buf, size_t size)
{
  switch(af) {
  case AF_INET:
    return inet_ntop4((const unsigned char *)src, buf, size);
  case AF_INET6:
    return inet_ntop6((const unsigned char *)src, buf, size);
  default:
    errno = EAFNOSUPPORT;
    return NULL;
  }
}