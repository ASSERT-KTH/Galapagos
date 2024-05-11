push_armor_filter (armor_filter_context_t *afx, iobuf_t iobuf)
{
  int rc;

  afx->refcount++;
  rc = iobuf_push_filter (iobuf, armor_filter, afx);
  if (rc)
    afx->refcount--;
  return rc;
}