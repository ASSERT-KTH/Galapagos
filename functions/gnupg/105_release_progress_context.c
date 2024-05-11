release_progress_context (progress_filter_context_t *pfx)
{
  if (!pfx)
    return;
  log_assert (pfx->refcount);
  if ( --pfx->refcount )
    return;
  xfree (pfx->what);
  xfree (pfx);
}