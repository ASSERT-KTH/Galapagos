put_membuf (membuf_t *mb, const void *buf, size_t len)
{
  if (mb->out_of_core || !len)
    return;

  if (mb->len + len >= mb->size)
    {
      char *p;

      mb->size += len + 1024;
      p = xtryrealloc (mb->buf, mb->size);
      if (!p)
        {
          mb->out_of_core = errno ? errno : ENOMEM;
          /* Wipe out what we already accumulated.  This is required
             in case we are storing sensitive data here.  The membuf
             API does not provide another way to cleanup after an
             error. */
          wipememory (mb->buf, mb->len);
          return;
        }
      mb->buf = p;
    }
  if (buf)
    memcpy (mb->buf + mb->len, buf, len);
  else
    memset (mb->buf + mb->len, 0, len);
  mb->len += len;
}