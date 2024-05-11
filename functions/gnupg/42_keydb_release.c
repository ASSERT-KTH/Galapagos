keydb_release (KEYDB_HANDLE hd)
{
  keyboxd_local_t kbl;

  if (!hd)
    return;

  if (DBG_CLOCK)
    log_clock ("keydb_release");
  if (!hd->use_keyboxd)
    internal_keydb_deinit (hd);
  else
    {
      kbl = hd->kbl;
      if (DBG_CLOCK)
        log_clock ("close_context (found)");
      if (!kbl->is_active)
        log_fatal ("closing inactive keyboxd context %p\n", kbl);
      kbl->is_active = 0;
      hd->kbl = NULL;
      hd->ctrl = NULL;
    }
  xfree (hd);
}