open_card (ctrl_t ctrl)
{
  /* If we ever got a card not present error code, return that.  Only
     the SERIALNO command and a reset are able to clear from that
     state. */
  if (ctrl->server_local->card_removed)
    return gpg_error (GPG_ERR_CARD_REMOVED);

  if ( IS_LOCKED (ctrl) )
    return gpg_error (GPG_ERR_LOCKED);

  if (ctrl->card_ctx)
    return 0;

  return select_application (ctrl, NULL, 0, NULL, 0);
}