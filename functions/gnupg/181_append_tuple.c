append_tuple (membuf_t *membuf, int tag, const void *value, size_t length)
{
  unsigned char buf[2];

  assert (tag >= 0 && tag <= 0xffff);
  assert (length <= 0xffff);

  buf[0] = tag >> 8;
  buf[1] = tag;
  put_membuf (membuf, buf, 2);
  buf[0] = length >> 8;
  buf[1] = length;
  put_membuf (membuf, buf, 2);
  if (length)
    put_membuf (membuf, value, length);
}