compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Try to compare on the specified keys first (if provided).
     Only two cases exist without any key: simple sort,
     and reversed unadorned sort. */
  if (keylist)
    {
      diff = keycompare (a, b);
      /* We return if the determined difference is not zero,
         which implies that the two lines are not same 
         or, if we are sorting ans seeking unique
         or, if we're ensuring stable sorting */
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* The below block is executed when the keys are equal
     (or when keys not provided) falling back to the 'default' comparison */
  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    diff = blen != 0 ? -1 : 0;
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* The function xmemcoll0 is aiding performance 
         as it avoids always appending '\0' to the buffers,
         giving about a 3% performance boost for small lines. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      
      /* This condition helps in determining dominance using length
         in case the lines are the same */
      if (diff == 0)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}