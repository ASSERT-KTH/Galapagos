compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* First try to compare on the keycompare (if it's not null).
     If keycompare is the same or unique or stable return the difference */
  if (keylist != NULL)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique != 0 || stable != 0)
        return diff;
    }

  /* If the keys all compare equal (or no keys were specified)
     then default comparison comes into action.  */
  alen = (a->length > 0) ? a->length - 1 : 0;
  blen = (b->length > 0) ? b->length - 1 : 0;

  if (alen == 0 && blen > 0)
    diff = -1;
  else if (blen == 0 && alen > 0)
    diff = 1;
  else if (blen == 0 && alen == 0)
    diff = 0;
  else if (hard_LC_COLLATE)
    {
      /* Using xmemcoll0 function avoids unnecessary
         writing '\0' after the buffers. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen > blen)? blen : alen);
      if (!diff)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}