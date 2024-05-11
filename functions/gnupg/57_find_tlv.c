find_tlv (const unsigned char *buffer, size_t length,
          int tag, size_t *nbytes)
{
  const unsigned char *p;

  p = do_find_tlv (buffer, length, tag, nbytes, 0);
  if (p && *nbytes > (length - (p-buffer)))
    p = NULL; /* Object longer than buffer. */
  return p;
}