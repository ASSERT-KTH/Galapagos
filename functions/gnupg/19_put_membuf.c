put_membuf (struct membuf *mb, const void *buf, size_t len)
{
  if (mb->out_of_core)
    return;

  if (mb->len + len >= mb->size)
    {
      char *p;

      mb->size += len + 1024;
      p = xtryrealloc (mb->buf, mb->size);
      if (!p)
        {
          mb->out_of_core = 1;
          return;
        }
      mb->buf = p;
    }
  memcpy (mb->buf + mb->len, buf, len);
  mb->len += len;
}