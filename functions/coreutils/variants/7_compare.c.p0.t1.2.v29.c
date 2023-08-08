compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* First try to compare on the specified keys (if any).
     The only two cases with no key at all are unadorned sort,
     and unadorned sort -r. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* If the keys all compare equal (or no keys were specified)
     fall through to the default comparison.  */
  alen = a->length >= 1 ? a->length - 1 : 0, blen = b->length >= 1 ? b->length - 1 : 0;

  if (alen <= 0)
    diff = - NONZERO (blen);
  else if (blen <= 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is a performance enhancement as
         it will not unconditionally write '\0' after the
         passed in buffers, which was seen to give around
         a 3% increase in performance for short lines.  */
      diff = xmemcoll0 (a->text, alen, b->text, blen);
    }
  else
    {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (!diff)
        diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;
    }

  return diff_reversed (diff, reverse);
}