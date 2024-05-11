smatch (unsigned char const **buf, size_t buflen, const char *token)
{
  size_t toklen = strlen (token);

  if (buflen != toklen || memcmp (*buf, token, toklen))
    return 0;
  *buf += toklen;
  return 1;
}