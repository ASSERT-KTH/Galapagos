keydb_search_reset (KEYDB_HANDLE hd)
{
  gpg_error_t err;

  if (!hd)
    return gpg_error (GPG_ERR_INV_ARG);

  if (DBG_CLOCK)
    log_clock ("%s", __func__);
  if (DBG_CACHE)
    log_debug ("%s (hd=%p)", __func__, hd);

  if (!hd->use_keyboxd)
    {
      err = internal_keydb_search_reset (hd);
      goto leave;
    }

  /* All we need is to tell search that a reset is pending.  Note that
   * keydb_new sets this flag as well.  To comply with the
   * specification of keydb_delete_keyblock we also need to clear the
   * ubid flag so that after a reset a delete can't be performed.  */
  hd->kbl->need_search_reset = 1;
  hd->last_ubid_valid = 0;
  err = 0;

 leave:
  return err;
}