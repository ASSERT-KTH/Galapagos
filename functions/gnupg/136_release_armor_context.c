release_armor_context (armor_filter_context_t *afx)
{
  if (!afx)
    return;
  log_assert (afx->refcount);
  if ( --afx->refcount )
    return;
  gcry_md_close (afx->crc_md);
  xfree (afx);
}