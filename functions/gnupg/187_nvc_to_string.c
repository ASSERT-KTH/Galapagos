nvc_to_string (nvc_t pk)
{
  gpg_error_t err;
  char *buf;
  size_t len;
  estream_t sink;

  sink = es_fopenmem (0, "rw");
  assert (sink);

  err = nvc_write (pk, sink);
  assert (err == 0);

  len = es_ftell (sink);
  buf = xmalloc (len+1);
  assert (buf);

  es_fseek (sink, 0, SEEK_SET);
  es_read (sink, buf, len, NULL);
  buf[len] = 0;

  es_fclose (sink);
  return buf;
}