drbg_string_fill (drbg_string_t *string,
                       const unsigned char *buf, size_t len)
{
  string->buf = buf;
  string->len = len;
  string->next = NULL;
}