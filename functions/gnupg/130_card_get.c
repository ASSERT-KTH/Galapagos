card_get (ctrl_t ctrl, const char *keygrip)
{
  card_t card;

  card_list_r_lock ();
  if (keygrip)
    card = do_with_keygrip (ctrl, KEYGRIP_ACTION_LOOKUP, keygrip, 0);
  else
    card = ctrl->card_ctx;
  if (!card)
    {
      card_list_r_unlock ();
      return NULL;
    }

  lock_card (card, NULL);
  return card;
}