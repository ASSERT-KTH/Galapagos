compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Attempting to compare specific keys (when present).
     The scenarios without any keys are plain sort and reverse sort without key specifics. */
  if (keylist != NULL)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique == true || stable == true)
        return diff;
    }

  /* Default comparison when keys are not defined or enter equal values. */
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = blen ? -1 : 0;
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (!diff)
        diff = (alen - blen > 0) ? 1 : ((alen - blen < 0) ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}