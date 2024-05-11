card_put (card_t card)
{
  /* We don't deallocate CARD here.  Instead, we keep it.  This is
     useful so that a card does not get reset even if only one session
     is using the card - this way the PIN cache and other cached data
     are preserved.  */
  unlock_card (card);
  card_list_r_unlock ();
}